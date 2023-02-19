// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/FormFactory.hpp>

#include <utility>

#include <maxGUI/FormConcept.hpp>
#if defined(MAX_PLATFORM_WINDOWS)
	#include <maxGUI/Win32String.hpp>
#endif

#if defined(MAX_PLATFORM_WINDOWS)
	namespace {

		static LPCTSTR maxgui_window_class_name = TEXT("maxGUI Window Class");
		static LPCTSTR maxgui_creation_parameters_property_name = TEXT("maxGUI Creation Parameters");
		static LPCTSTR maxgui_formconcept_property_name = TEXT("maxGUI Form Concept");


		maxGUI::FormConcept* GetFormFromHWND(HWND window_handle) {
			maxGUI::FormConcept* form = nullptr;

			HANDLE property = ::GetProp(window_handle, maxgui_formconcept_property_name);
			if (property != NULL) {
				form = reinterpret_cast<maxGUI::FormConcept*>(property);
			}

			return form;
		}

		LRESULT CALLBACK BaseWindowProcedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
			switch (message)
			{
			case WM_NCCREATE:
			{
				CREATESTRUCT* creation_parameters = reinterpret_cast<CREATESTRUCT*>(lparam);
				if (creation_parameters)
				{
					maxGUI::FormFactory* form_factory = reinterpret_cast<maxGUI::FormFactory*>(creation_parameters->lpCreateParams);
					BOOL result = SetProp(window_handle, maxgui_creation_parameters_property_name, static_cast<HANDLE>(form_factory));
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
					maxGUI::FormFactory* form_factory = reinterpret_cast<maxGUI::FormFactory*>(property);
					std::unique_ptr<maxGUI::FormConcept> created_form = form_factory->form_allocator_->AllocateForm(window_handle);

					RemoveProp(window_handle, maxgui_creation_parameters_property_name);

					BOOL result = SetProp(window_handle, maxgui_formconcept_property_name, static_cast<HANDLE>(created_form.get()));
					if (result == 0) {
						return -1;
					}
					form = created_form.get();

					form_factory->form_container_->forms_.push_back(std::move(created_form));
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
			}

			auto form = GetFormFromHWND(window_handle);
			if (form) {
				return form->OnWindowMessage(form, message, wparam, lparam);
			}

			return DefWindowProc(window_handle, message, wparam, lparam);
		}

	} // anonymous namespace
#endif

namespace maxGUI {

	FormFactory::FormFactory(std::unique_ptr<FormAllocatorConcept> form_allocator) noexcept
		: form_allocator_(std::move(form_allocator))
	{}

	#if defined(MAX_PLATFORM_WINDOWS)
		bool FormFactory::CreateForm(HINSTANCE instance_handle, int width, int height, std::string title, FormStyles styles) noexcept {
			WNDCLASSEX wcx = {0};
			wcx.cbSize = sizeof(wcx);
			wcx.style = 0;
			wcx.lpfnWndProc = BaseWindowProcedure;
			wcx.cbClsExtra = 0;
			wcx.cbWndExtra = 0;
			wcx.hInstance = instance_handle;
			//wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
			wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
			//wcx.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
			//wcx.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
			wcx.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BTNFACE + 1);
			wcx.lpszMenuName = NULL;
			wcx.lpszClassName = maxgui_window_class_name;
			//wcx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
			// TODO: Add the ability to package resources into the executable and use them
			wcx.hIcon = reinterpret_cast< HICON >( LoadImageW( instance_handle, IDI_APPLICATION, IMAGE_ICON, 32, 32, LR_CREATEDIBSECTION ) );
			wcx.hIconSm = reinterpret_cast< HICON >( LoadImageW( instance_handle, IDI_APPLICATION, IMAGE_ICON, 16, 16, LR_CREATEDIBSECTION ) );

			/*ATOM atom = */RegisterClassEx(&wcx);

			int virtual_top = CW_USEDEFAULT;
			int virtual_left = CW_USEDEFAULT;

			RECT area = {0};
			area.top = 0;
			area.left = 0;
			area.bottom = height;
			area.right = width;

			DWORD win32_styles = 0;
			if ((styles & FormStyles::FixedSize) == FormStyles::FixedSize) {
				win32_styles |= WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;// | WS_CLIPCHILDREN;
			} else {
				win32_styles |= WS_OVERLAPPEDWINDOW;
			}
			if ((styles & FormStyles::DialogBox) == FormStyles::DialogBox) {
				win32_styles |= WS_DLGFRAME;
			}
			DWORD extra_style = WS_EX_CONTROLPARENT | WS_EX_CLIENTEDGE; //WS_EX_WINDOWEDGE;

			AdjustWindowRectEx(&area, win32_styles, FALSE, extra_style);
			LONG total_height = 0;
			LONG total_width = 0;
			if (virtual_top == CW_USEDEFAULT)
			{
				area.bottom -= area.top;
				total_height = area.bottom - area.top;
				area.top = CW_USEDEFAULT;
			} else {
				area.top = virtual_top;
				area.bottom += virtual_top;
				total_height = area.bottom - area.top;
			}
			if (virtual_left == CW_USEDEFAULT)
			{
				area.right -= area.left;
				total_width = area.right - area.left;
				area.left = CW_USEDEFAULT;
			} else {
				area.left = virtual_left;
				area.right += virtual_left;
				total_width = area.right - area.left;
			}

			Win32String win32_title = Utf8ToWin32String(title);
			HWND window_handle = CreateWindowEx(extra_style, /*reinterpret_cast<LPCWSTR>(atom)*/maxgui_window_class_name, win32_title.text_, win32_styles, area.left, area.top, total_width, total_height, 0, 0, instance_handle, static_cast<LPVOID>(this));
			if (window_handle == NULL) {
				return false;
			}

			ShowWindow(window_handle, SW_SHOWNORMAL);
			UpdateWindow(window_handle);

			return true;
		}
	#elif defined(MAX_PLATFORM_LINUX)
		bool FormFactory::CreateForm(int width, int height, std::string title, FormStyles styles) noexcept {
			std::unique_ptr<FormConcept> created_form = form_allocator_->AllocateForm(std::move(width), std::move(height), std::move(title), std::move(styles));
			FormConcept* form = created_form.get();
			form_container_->forms_.push_back(std::move(created_form));
			form->OnCreated(form);
			return true;
		}
	#endif

} // namespace maxGUI