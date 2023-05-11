// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/FormContainer.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
namespace {

	maxGUI::FormConcept* GetFormFromHWND(HWND window_handle) {
		maxGUI::FormConcept* form = nullptr;

		HANDLE property = ::GetProp(window_handle, maxGUI::FormContainer::maxgui_formconcept_property_name);
		if (property != NULL) {
			form = reinterpret_cast<maxGUI::FormConcept*>(property);
		}

		return form;
	}

} // anonymous namespace
#endif // #if defiend(MAX_PLATFORM_WINDOWS)

namespace maxGUI {

	#if defined(MAX_PLATFORM_WINDOWS)
		LPCTSTR FormContainer::maxgui_window_class_name = TEXT("maxGUI Window Class");
		LPCTSTR FormContainer::maxgui_creation_parameters_property_name = TEXT("maxGUI Creation Parameters");
		LPCTSTR FormContainer::maxgui_formconcept_property_name = TEXT("maxGUI Form Concept");

		FormContainer::FormContainer(HINSTANCE instance_handle) noexcept
			: instance_handle_(instance_handle)
		{}
	#elif defined(MAX_PLATFORM_LINUX)
		FormContainer::FormContainer(QApplication* app) noexcept
			: app_(std::move(app))
		{}
	#endif

	#if defined(MAX_PLATFORM_WINDOWS)
		LRESULT CALLBACK FormContainer::BaseWindowProcedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
			switch (message)
			{
			case WM_NCCREATE:
			{
				CREATESTRUCT* creation_parameters = reinterpret_cast<CREATESTRUCT*>(lparam);
				if (creation_parameters)
				{
					auto* typed_creation_parameters = reinterpret_cast<maxGUI::FormContainer::CreationParameters*>(creation_parameters->lpCreateParams);
					BOOL result = SetProp(window_handle, maxgui_creation_parameters_property_name, static_cast<HANDLE>(typed_creation_parameters));
					if (result == 0) {
						return -1;
					}
				}
			}
			return DefWindowProc(window_handle, message, wparam, lparam);
			case WM_CREATE:
			{
				maxGUI::FormConcept* form = nullptr;
				HANDLE property = GetProp(window_handle, maxgui_creation_parameters_property_name);
				if (property != NULL) {
					auto* typed_creation_parameters = reinterpret_cast<maxGUI::FormContainer::CreationParameters*>(property);
					std::unique_ptr<maxGUI::FormConcept> created_form = typed_creation_parameters->form_allocator_->AllocateForm(window_handle);

					RemoveProp(window_handle, maxgui_creation_parameters_property_name);

					BOOL result = SetProp(window_handle, maxgui_formconcept_property_name, static_cast<HANDLE>(created_form.get()));
					if (result == 0) {
						return -1;
					}
					form = created_form.get();

					// TODO: How am I going to get the form container? Maybe it gets passed in via the allocator, too? A tuple?
					typed_creation_parameters->form_container_->forms_.push_back(std::move(created_form));
				}

				form->OnCreated(form);
			}
			//return 0;
			return DefWindowProc(window_handle, message, wparam, lparam);
			case WM_SIZE:
			{
				auto form = GetFormFromHWND(window_handle);

				int height = HIWORD(lparam);
				int width = LOWORD(lparam);

				form->OnResized(form, width, height);
			}
			return TRUE;
			// TODO: This should be WM_CLOSE
			case WM_DESTROY:
			{
				auto form = GetFormFromHWND(window_handle);
				form->OnClosed(form);
			}
			return 0;
			case WM_NCDESTROY:
				RemoveProp(window_handle, maxgui_formconcept_property_name);
				return 0;
			case WM_COMMAND:
			{
				auto form = GetFormFromHWND(window_handle);
				if (HIWORD(wparam) == 0 && lparam == 0) // menu
				{
					//auto menu_identifier = LOWORD(wparam);
				} else if (HIWORD(wparam) == 1 && lparam == 0) { // accelerator
					//auto accelerator_identifier = LOWORD(wparam);
				} else {
					//auto control_identifier = LOWORD(wparam);
					HWND control_window_handle = reinterpret_cast<HWND>(lparam);
					for (auto& control : form->controls_) {
						if (control->window_handle_ == control_window_handle) {
							control->OnCommand(HIWORD(wparam));
						}
					}
				}
			}
			return 0;
			case WM_SETTINGCHANGE:
			{
				DWORD is_light_mode = {0};
				DWORD size = sizeof(is_light_mode);
				auto result = RegGetValueW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", L"AppsUseLightTheme", RRF_RT_REG_DWORD, nullptr, &is_light_mode, &size);
				if (result != ERROR_SUCCESS) {
					// Not supported
					return 0;
				}

				BOOL is_dark_mode = !is_light_mode;
				DwmSetWindowAttribute(window_handle, DWMWA_USE_IMMERSIVE_DARK_MODE, &is_dark_mode, sizeof(is_dark_mode));
			}
			return 0;
			}

			auto form = GetFormFromHWND(window_handle);
			if (form) {
				return form->OnWindowMessage(form, message, wparam, lparam);
			}

			return DefWindowProc(window_handle, message, wparam, lparam);
		}
	#endif

} // namespace maxGUI