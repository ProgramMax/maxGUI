// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/TextBox.hpp>

#include <maxGUI/Win32String.hpp>
#include <type_traits>
#include <utility>

namespace maxGUI
{

	TextBox::TextBox(HWND window_handle) noexcept
		: ControlWithText(std::move(window_handle))
	{}
	
	HWND TextBoxFactoryImplementationDetails::CreateTextBox(std::string text, Rectangle rectangle, TextBoxStyles styles, HWND parent_window_handle) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL;
		if ((styles & TextBoxStyles::Password) == TextBoxStyles::Password) {
			win32_styles |= ES_PASSWORD;
		}
		if ((styles & TextBoxStyles::ReadOnly) == TextBoxStyles::ReadOnly) {
			win32_styles |= ES_READONLY;
		}

		//EM_GETSEL - Gets the starting (low-order word) and ending (first nonselected char, high-order word) character positions of the current selection.
		//EM_LIMITTEXT - wParam holds max number of chars. If this is zero, the text length is set to the maximum number of bytes possible.
		//EM_REPLACESEL - pointer to the text in the lParam parameter. The new text must be null-terminated.
		//EM_SETPASSWORDCHAR - new password character in the wParam parameter. Doesn't work on multi-line
		//EM_SETSEL - lParam specifies the starting (low-order word) and ending (high-order word) character for the selection. 
			//To select the 10th through 20th characters in an edit control: 
			//SendMessage(hEditWnd, EM_SETSEL, 0, MAKELONG(9,19) );
			//To deselect a selection: 
			//SendMessage(hEditWnd, EM_SETSEL, 0, MAKELONG(0xffff, 0) );
			//To set the caret at the end of the edit control: 
			//SendMessage(hEditWnd, EM_SETSEL, 0, MAKELONG(0xffff, 0xffff) );
			//To set the caret after the position of the Nth character: 
			//SendMessage(hEditWnd, EM_SETSEL, 0, MAKELONG(N, N) );
		//EN_UPDATE - text changed

		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), win32_text.text_, win32_styles, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI