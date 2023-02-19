// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/CheckBox.hpp>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{
	
	CheckBox::CheckBox(HWND window_handle) noexcept
		: ControlWithText(std::move(window_handle))
	{}

	HWND CheckBox::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, CheckBoxStyles styles) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_CHECKBOX;
		// MSVC at warning level 4 issues C26813 because it wants "if (styles & ButtonStyles::Default) {"
		// But this doesn't play nicely with enum classes because ultimately it needs to convert to bool.
		// See https://developercommunity.visualstudio.com/t/C26813-incompatible-with-enum-class/10145182
		#pragma warning(push)
		#pragma warning(disable: 26813)
		if ((styles & CheckBoxStyles::Disabled) == CheckBoxStyles::Disabled) {
			win32_styles |= WS_DISABLED;
		}
		if ((styles & CheckBoxStyles::Flat) == CheckBoxStyles::Flat) {
			win32_styles |= BS_FLAT;
		}
		#pragma warning(pop)
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, win32_styles, rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

	void CheckBox::OnPressed() noexcept {
		if (IsChecked()) {
			Uncheck();
		} else {
			Check();
		}
	}

	void CheckBox::OnCommand(WORD notification) noexcept {
		if (notification == BN_CLICKED)
		{
			OnPressed();
		}
	}

	bool CheckBox::IsChecked() const noexcept {
		return SendMessage(window_handle_, BM_GETCHECK, 0, 0) == BST_CHECKED;
	}

	void CheckBox::Check() noexcept {
		SendMessage(window_handle_, BM_SETCHECK, BST_CHECKED, 0);
	}

	void CheckBox::Uncheck() noexcept {
		SendMessage(window_handle_, BM_SETCHECK, BST_UNCHECKED, 0);
	}

} //  namespace maxGUI