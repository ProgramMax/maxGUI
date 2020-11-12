// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/RadioButton.hpp>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{
	
	RadioButton::RadioButton(HWND window_handle) noexcept
		: ControlWithText(std::move(window_handle))
	{}

	void RadioButton::OnPressed() noexcept
	{}

	void RadioButton::OnCommand(WORD notification) noexcept {
		if (notification == BN_CLICKED) {
			OnPressed();
		}
	}

	HWND RadioButtonFactoryImplementationDetails::CreateRadioButton(std::string text, Rectangle rectangle, RadioButtonStyles style, HWND parent_window_handle) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON;
		if ((style & RadioButtonStyles::FirstInGroup) == RadioButtonStyles::FirstInGroup) {
			win32_styles |= WS_GROUP | WS_TABSTOP;
		}
		if ((style & RadioButtonStyles::Flat) == RadioButtonStyles::Flat) {
			win32_styles |= BS_FLAT;
		}
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, win32_styles, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI