// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Form.hpp>
#include <maxGUI/EntryPoint.hpp>
#include <maxGUI/Win32String.hpp>
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

	LRESULT CALLBACK BaseWindowProcedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
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
			return DefWindowProc(window_handle, message, wparam, lparam);
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
			//return 0;
			return DefWindowProc(window_handle, message, wparam, lparam);
		case WM_SIZE:
			{
				auto form = GetFormFromHWND(window_handle);

				int height = HIWORD(lparam);
				int width = LOWORD(lparam);
				form->OnResized(height, width);
			}
			return TRUE;
		// TODO: This should be WM_CLOSE
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

		auto form = GetFormFromHWND(window_handle);
		if (form) {
			return form->OnWindowMessage(message, wparam, lparam);
		}

		return DefWindowProc(window_handle, message, wparam, lparam);
	}

} // anonymous namespace

namespace maxGUI {

	Form::Form(HWND window_handle) noexcept
		: window_handle_(window_handle)
	{}

	void Form::OnCreated() noexcept {
	}

	void Form::OnResized(int /*new_width*/, int /*new_height*/) noexcept {
	}

	void Form::OnClosed() noexcept {
		PostExitMessage(0);
	}

	LRESULT Form::OnWindowMessage(UINT message, WPARAM wparam, LPARAM lparam) noexcept {
		return DefWindowProc(window_handle_, message, wparam, lparam);
	}

	Control* Form::AddControl(const ControlFactory* control_factory) noexcept {
		std::unique_ptr<Control> control_ptr = control_factory->CreateControl(window_handle_);
		Control* raw_control_ptr = control_ptr.get();
		controls_.push_back(std::move(control_ptr));
		return raw_control_ptr;
	}

	FormContainer::FormContainer(HINSTANCE instance_handle) noexcept
		: instance_handle_(instance_handle)
	{}

	bool FormFactoryImplementationDetails::CreateForm(HINSTANCE instance_handle, int height, int width, std::string title) noexcept {
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
		wcx.hIcon = reinterpret_cast< HICON >( LoadImageW( instance_handle, IDI_APPLICATION, IMAGE_ICON, 32, 32, LR_CREATEDIBSECTION ) );
		wcx.hIconSm = reinterpret_cast< HICON >( LoadImageW( instance_handle, IDI_APPLICATION, IMAGE_ICON, 16, 16, LR_CREATEDIBSECTION ) );

		/*ATOM atom = */RegisterClassEx(&wcx);

		int virtual_top = CW_USEDEFAULT;
		int virtual_left = CW_USEDEFAULT;

		RECT area;
		area.top = 0;
		area.left = 0;
		area.bottom = height;
		area.right = width;

		//DWORD style = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN;
		//DWORD extra_style = NULL;
		//DWORD extra_style = WS_EX_CLIENTEDGE;

		DWORD style = WS_BORDER | WS_CAPTION /*| WS_MINIMIZEBOX*/ | WS_SYSMENU | WS_POPUP | WS_OVERLAPPEDWINDOW;// | WS_CLIPCHILDREN;
		DWORD extra_style = WS_EX_CONTROLPARENT | WS_EX_CLIENTEDGE; //WS_EX_WINDOWEDGE;

		//DWORD ExtraStyle = WS_EX_CONTROLPARENT /* has controls which should participate in dialog stuff */ | WS_EX_WINDOWEDGE;

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

		Win32String win32_title = Utf8ToWin32String(title);
		HWND window_handle = CreateWindowEx(extra_style, /*reinterpret_cast<LPCWSTR>(atom)*/maxgui_window_class_name, win32_title.text_, style, area.left, area.top, total_width, total_height, 0, 0, instance_handle, static_cast<LPVOID>(this));
		if (window_handle == NULL) {
			return false;
		}

		ShowWindow(window_handle, SW_SHOWNORMAL);
		UpdateWindow(window_handle);

		return true;
	}

} // namespace maxGUI