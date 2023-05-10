// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/DropDownBoxImplementation.hpp>

#include <utility>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{

	DropDownBoxImplementation::DropDownBoxImplementation(HWND window_handle) noexcept
		: ControlWithTextImplementation(std::move(window_handle))
	{}

	DropDownBoxImplementation::~DropDownBoxImplementation() noexcept = default;

	HWND DropDownBoxImplementation::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::vector<std::string> list, DropDownBoxStyles styles) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWN | CBS_HASSTRINGS /*| CBS_DROPDOWNLIST*/;
		// MSVC at warning level 4 issues C26813 because it wants "if (styles & ButtonStyles::Default) {"
		// But this doesn't play nicely with enum classes because ultimately it needs to convert to bool.
		// See https://developercommunity.visualstudio.com/t/C26813-incompatible-with-enum-class/10145182
#pragma warning(push)
#pragma warning(disable: 26813)
		if ((styles & DropDownBoxStyles::Disabled) == DropDownBoxStyles::Disabled) {
			win32_styles |= WS_DISABLED;
		}
#pragma warning(pop)
		HWND window_handle = CreateWindowEx(0, TEXT("COMBOBOX"), TEXT(""), win32_styles, rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);

		for (const auto& text : list) {
			Win32String win32_text = Utf8ToWin32String(text);
			SendMessage(window_handle, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(win32_text.text_));
		}

		// Default select the first item
		if (list.size() != 0) {
			SendMessage(window_handle, CB_SETCURSEL, 0, 0);
		}

		return window_handle;
	}

} // namespace maxGUI