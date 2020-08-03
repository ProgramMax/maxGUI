// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ListBox.hpp>

#include <maxGUI/Win32String.hpp>
#include <utility>

namespace maxGUI
{
	
	ListBox::ListBox(HWND window_handle) noexcept
		: Control(std::move(window_handle))
	{}

	HWND ListBoxFactoryImplementationDetails::CreateListBox(Rectangle rectangle, std::vector<std::string> list, HWND parent_window_handle) noexcept {
		// LBS_MULTIPLESEL
		// LBS_EXTENDEDSEL
		HWND window_handle = CreateWindowEx(0, TEXT("LISTBOX"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_TABSTOP | LBS_STANDARD, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);

		for (const auto& text : list) {
			Win32String win32_text = Utf8ToWin32String(text);
			SendMessage(window_handle, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>(win32_text.text_));
		}

		return window_handle;
	}

} //  namespace maxGUI