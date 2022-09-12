// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Button.hpp>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{
	
	Button::Button(HWND window_handle) noexcept
		: ControlWithText(std::move(window_handle))
	{}

	void Button::OnCommand(WORD notification) noexcept {
		if (notification == BN_CLICKED)
		{
			OnPressed();
		}
	}

	HWND ButtonFactoryImplementationDetails::CreateButton(std::string text, Rectangle rectangle, ButtonStyles styles, HWND parent_window_handle) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_TABSTOP;
		if ((styles & ButtonStyles::Default) == ButtonStyles::Default) {
			win32_styles |= BS_DEFPUSHBUTTON;
		}
		if ((styles & ButtonStyles::Flat) == ButtonStyles::Flat) {
			win32_styles |= BS_FLAT;
		}
		Win32String win32_text = Utf8ToWin32String(std::move(text));

		return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, win32_styles, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI