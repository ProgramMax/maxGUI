// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/CheckBox.hpp>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{
	
	CheckBox::CheckBox(HWND window_handle) MAX_DOES_NOT_THROW
		: ControlWithText(std::move(window_handle))
	{}

	void CheckBox::OnPressed() MAX_DOES_NOT_THROW {
		if (IsChecked()) {
			Uncheck();
		} else {
			Check();
		}
	}

	void CheckBox::OnCommand(WORD notification) MAX_DOES_NOT_THROW {
		if (notification == BN_CLICKED)
		{
			OnPressed();
		}
	}

	bool CheckBox::IsChecked() const MAX_DOES_NOT_THROW {
		return SendMessage(window_handle_, BM_GETCHECK, 0, 0);
	}

	void CheckBox::Check() MAX_DOES_NOT_THROW {
		SendMessage(window_handle_, BM_SETCHECK, BST_CHECKED, 0);
	}

	void CheckBox::Uncheck() MAX_DOES_NOT_THROW {
		SendMessage(window_handle_, BM_SETCHECK, BST_UNCHECKED, 0);
	}

	HWND CheckBoxFactoryImplementationDetails::CreateCheckBox(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW {
		// BS_DEFPUSHBUTTON
		// BS_FLAT


		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_CHECKBOX, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI