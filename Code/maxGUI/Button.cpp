// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Button.hpp>


#include <maxGUI/Win32String.hpp>
#include <utility>

namespace maxGUI
{
	
	Button::Button(HWND window_handle) MAX_DOES_NOT_THROW
		: ControlWithText(std::move(window_handle))
	{}

	void Button::OnCommand(WORD notification) MAX_DOES_NOT_THROW {
		if (notification == BN_CLICKED)
		{
			OnPressed();
		}
	}

	HWND ButtonFactoryImplementationDetails::CreateButton(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW {
		// BS_DEFPUSHBUTTON
		// BS_FLAT
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("BUTTON"), win32_text.text_, WS_CHILD | WS_VISIBLE | WS_TABSTOP, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI