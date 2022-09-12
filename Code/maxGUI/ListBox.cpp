// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ListBox.hpp>

#include <maxGUI/Win32String.hpp>
#include <utility>

namespace maxGUI
{
	
	ListBox::ListBox(HWND window_handle) noexcept
		: ControlWithList(std::move(window_handle))
	{}

	void ListBox::OnCommand(WORD notification) noexcept {
		if (notification == LBN_SELCHANGE)
		{
			int index = static_cast<int>(SendMessage(window_handle_, LB_GETCURSEL, 0, 0));
			OnSelectionChanged(index);
		}
	}

	HWND ListBoxFactoryImplementationDetails::CreateListBox(Rectangle rectangle, std::vector<std::string> list, ListBoxStyles styles, HWND parent_window_handle) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_TABSTOP | LBS_STANDARD;
		// MSVC at warning level 4 issues C26813 because it wants "if (styles & ButtonStyles::Default) {"
		// But this doesn't play nicely with enum classes because ultimately it needs to convert to bool.
		// See https://developercommunity.visualstudio.com/t/C26813-incompatible-with-enum-class/10145182
		#pragma warning(push)
		#pragma warning(disable: 26813)
		if ((styles & ListBoxStyles::Disabled) == ListBoxStyles::Disabled) {
			win32_styles |= WS_DISABLED;
		}
		if ((styles & ListBoxStyles::SingleClickMultipleSelection) == ListBoxStyles::SingleClickMultipleSelection) {
			win32_styles |= LBS_MULTIPLESEL;
		}
		if ((styles & ListBoxStyles::KeyboardAndClickMultipleSelection) == ListBoxStyles::KeyboardAndClickMultipleSelection) {
			win32_styles |= LBS_EXTENDEDSEL;
		}
		#pragma warning(pop)
		HWND window_handle = CreateWindowEx(0, TEXT("LISTBOX"), TEXT(""), win32_styles, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);

		for (const auto& text : list) {
			Win32String win32_text = Utf8ToWin32String(text);
			SendMessage(window_handle, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>(win32_text.text_));
		}

		return window_handle;
	}

} //  namespace maxGUI