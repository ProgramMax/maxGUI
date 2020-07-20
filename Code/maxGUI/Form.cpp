// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Form.hpp>
#include <maxGUI/EntryPoint.hpp>
#include <utility>

namespace {

	static LPCTSTR maxgui_window_class_name = TEXT("maxGUI Window Class");
	static LPCTSTR maxgui_creation_parameters_property_name = TEXT("maxGUI Creation Parameters");
	static LPCTSTR maxgui_form_property_name = TEXT("maxGUI Form");

	maxGUI::Form* GetFormFromHWND(HWND window_handle) {
		maxGUI::Form* form = nullptr;

		HANDLE property = ::GetProp(window_handle, maxgui_form_property_name);
		if (property != NULL) {
			form = reinterpret_cast<maxGUI::Form*>(property);
		}

		return form;
	}

	LRESULT CALLBACK BaseWindowProcedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam) MAX_DOES_NOT_THROW {
		switch (message)
		{
		case WM_NCCREATE:
			{
				CREATESTRUCT* creation_parameters = reinterpret_cast<CREATESTRUCT*>(lparam);
				if (creation_parameters)
				{
					maxGUI::FormFactoryImplementationDetails* form_factory_implementation_details = reinterpret_cast<maxGUI::FormFactoryImplementationDetails*>(creation_parameters->lpCreateParams);
					BOOL result = SetProp(window_handle, maxgui_creation_parameters_property_name, static_cast<HANDLE>(form_factory_implementation_details));
					if (result == 0) {
						return -1;
					}
				}
			}
			return TRUE;
		case WM_CREATE:
			{
				maxGUI::Form* form = nullptr;
				HANDLE property = GetProp(window_handle, maxgui_creation_parameters_property_name);
				if (property != NULL) {
					maxGUI::FormFactoryImplementationDetails* form_factory_implementation_details = reinterpret_cast<maxGUI::FormFactoryImplementationDetails*>(property);
					std::unique_ptr<maxGUI::Form> created_form = form_factory_implementation_details->AllocateForm(window_handle);

					RemoveProp(window_handle, maxgui_creation_parameters_property_name);

					BOOL result = SetProp(window_handle, maxgui_form_property_name, static_cast<HANDLE>(created_form.get()));
					if (result == 0) {
						return -1;
					}
					form = created_form.get();

					form_factory_implementation_details->form_container_->forms_.push_back(std::move(created_form));
				}
				form->OnCreated();
			}
			return 0;
		case WM_SIZE:
			{
				auto form = GetFormFromHWND(window_handle);

				int height = HIWORD(lparam);
				int width = LOWORD(lparam);
				form->OnResized(height, width);
			}
			return TRUE;
		case WM_DESTROY:
			{
				auto form = GetFormFromHWND(window_handle);
				form->OnClosed();
			}
			return 0;
		case WM_NCDESTROY:
			RemoveProp(window_handle, maxgui_form_property_name);
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

		return DefWindowProc(window_handle, message, wparam, lparam);
	}

} // anonymous namespace

namespace maxGUI {

	Form::Form(HWND window_handle) MAX_DOES_NOT_THROW
		: window_handle_(window_handle)
	{}

	void Form::OnCreated() MAX_DOES_NOT_THROW {
	}

	void Form::OnResized(int /*new_width*/, int /*new_height*/) MAX_DOES_NOT_THROW {
	}

	void Form::OnClosed() MAX_DOES_NOT_THROW {
		PostExitMessage(0);
	}

	Control* Form::AddControl(const ControlFactory* control_factory) MAX_DOES_NOT_THROW {
		std::unique_ptr<Control> control_ptr = control_factory->CreateControl(window_handle_);
		Control* raw_control_ptr = control_ptr.get();
		controls_.push_back(std::move(control_ptr));
		return raw_control_ptr;
	}

	FormContainer::FormContainer(HINSTANCE instance_handle) MAX_DOES_NOT_THROW
		: instance_handle_(instance_handle)
	{}

	bool FormFactoryImplementationDetails::CreateForm(HINSTANCE instance_handle, int height, int width, std::string title) MAX_DOES_NOT_THROW {
		WNDCLASSEX wcx = {0};
		wcx.cbSize = sizeof(wcx);
		wcx.style = 0;
		wcx.lpfnWndProc = BaseWindowProcedure;
		wcx.cbClsExtra = 0;
		wcx.cbWndExtra = 0;
		wcx.hInstance = instance_handle;
		wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
		//wcx.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		wcx.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcx.lpszMenuName = NULL;
		wcx.lpszClassName = maxgui_window_class_name;
		wcx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		ATOM atom = RegisterClassEx(&wcx);

		int virtual_top = CW_USEDEFAULT;
		int virtual_left = CW_USEDEFAULT;

		RECT area;
		area.top = 0;
		area.left = 0;
		area.bottom = height;
		area.right = width;

		DWORD style = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN;
		//DWORD extra_style = NULL;
		DWORD extra_style = WS_EX_CLIENTEDGE;

		AdjustWindowRectEx(&area, style, FALSE, extra_style);
		DWORD total_height = 0;
		DWORD total_width = 0;
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

		// TODO: Allow specific window title
		HWND window_handle = CreateWindowEx(extra_style, reinterpret_cast<LPCWSTR>(atom), TEXT("Test"), style, area.left, area.top, total_width, total_height, 0, 0, instance_handle, static_cast<LPVOID>(this));
		if (window_handle == NULL) {
			return false;
		}

		ShowWindow(window_handle, SW_SHOWNORMAL);
		UpdateWindow(window_handle);

		return true;
	}

} // namespace maxGUI