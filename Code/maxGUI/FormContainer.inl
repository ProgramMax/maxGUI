// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/FormContainer.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#include <maxGUI/Win32String.hpp>
#endif

namespace maxGUI {

#if defined(MAX_PLATFORM_WINDOWS)
	template <typename FormType>
	bool FormContainer::CreateForm(int width, int height, std::string title, FormAllocatorConcept* form_allocator, FormStyles styles) noexcept {
		WNDCLASSEX wcx = {0};
		wcx.cbSize = sizeof(wcx);
		wcx.style = 0;
		wcx.lpfnWndProc = BaseWindowProcedure;
		wcx.cbClsExtra = 0;
		wcx.cbWndExtra = 0;
		wcx.hInstance = instance_handle_;
		//wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
		//wcx.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		//wcx.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcx.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BTNFACE + 1);
		wcx.lpszMenuName = NULL;
		wcx.lpszClassName = maxgui_window_class_name;
		//wcx.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		// TODO: Add the ability to package resources into the executable and use them
		wcx.hIcon = reinterpret_cast< HICON >( LoadImageW( instance_handle_, IDI_APPLICATION, IMAGE_ICON, 32, 32, LR_CREATEDIBSECTION ) );
		wcx.hIconSm = reinterpret_cast< HICON >( LoadImageW( instance_handle_, IDI_APPLICATION, IMAGE_ICON, 16, 16, LR_CREATEDIBSECTION ) );

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
		// CreateWindowEx doesn't return until WM_CREATE is passed to the proc.
		// So it is safe to use the stack for creation_parameters.
		CreationParameters creation_parameters(std::move(form_allocator), this);
		HWND window_handle = CreateWindowEx(extra_style, /*reinterpret_cast<LPCWSTR>(atom)*/maxgui_window_class_name, win32_title.text_, win32_styles, area.left, area.top, total_width, total_height, 0, 0, instance_handle_, static_cast<LPVOID>(&creation_parameters));
		if (window_handle == NULL) {
			return false;
		}

		ShowWindow(window_handle, SW_SHOWNORMAL);
		UpdateWindow(window_handle);

		return true;
	}
#elif defined(MAX_PLATFORM_LINUX)
	template <typename FormType>
	bool FormContainer::CreateForm(int width, int height, std::string title, FormAllocatorConcept* form_allocator, FormStyles styles) noexcept {
		std::unique_ptr<FormConcept> created_form = form_allocator->AllocateForm(std::move(width), std::move(height), std::move(title), std::move(styles));
		FormConcept* form = created_form.get();
		forms_.push_back(std::move(created_form));
		form->OnCreated(form);
		return true;
	}
#endif

} // namespace maxGUI