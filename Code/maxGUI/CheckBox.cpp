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
		return SendMessage(window_handle_, BM_GETCHECK, 0, 0);
	}

	void CheckBox::Check() noexcept {
		SendMessage(window_handle_, BM_SETCHECK, BST_CHECKED, 0);
	}

	void CheckBox::Uncheck() noexcept {
		SendMessage(window_handle_, BM_SETCHECK, BST_UNCHECKED, 0);
	}

	HWND CheckBoxFactoryImplementationDetails::CreateCheckBox(std::string text, Rectangle rectangle, CheckBoxStyles styles, HWND parent_window_handle) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_CHECKBOX;
		if ((styles & CheckBoxStyles::Flat) == CheckBoxStyles::Flat) {
			win32_styles |= BS_FLAT;
		}
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, win32_styles, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI