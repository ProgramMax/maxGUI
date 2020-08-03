// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/DropDownBox.hpp>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{
	
	DropDownBox::DropDownBox(HWND window_handle) noexcept
		: ControlWithList(std::move(window_handle))
	{}

	void DropDownBox::OnCommand(WORD notification) noexcept {
		if (notification == CBN_SELCHANGE)
		{
			int index = static_cast<int>(SendMessage(window_handle_, CB_GETCURSEL, 0, 0));
			OnSelectionChanged(index);
		}
	}
	
	HWND DropDownBoxFactoryImplementationDetails::CreateDropDownBox(Rectangle rectangle, std::vector<std::string> list, HWND parent_window_handle) noexcept {
		HWND window_handle = CreateWindowEx(0, TEXT("COMBOBOX"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWN | CBS_HASSTRINGS /*| CBS_DROPDOWNLIST*/, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);

		for (const auto& text : list) {
			Win32String win32_text = Utf8ToWin32String(text);
			SendMessage(window_handle, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(win32_text.text_));
		}

		// Default select the first item
		if (list.size() != 0) {
			SendMessage(window_handle, CB_SETCURSEL, 0, 0);
		}

		return window_handle;
	};

} //  namespace maxGUI