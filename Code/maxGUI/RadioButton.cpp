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

	HWND RadioButtonFactoryImplementationDetails::CreateRadioButton(std::string text, Rectangle rectangle, HWND parent_window_handle) noexcept {
		// WS_GROUP should go on the first control in a group.
		// For example, if there are 3 radio buttons, the first one should get WS_GROUP

		// TODO: This is a disgusting hack to allow one set of radio buttons. Make a proper grouping.
		static bool first = true;
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		if (first) {
			first = false;
			return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_AUTORADIOBUTTON, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
		} else {
			return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, WS_CHILD | WS_VISIBLE | /*WS_GROUP |*/ WS_TABSTOP | BS_AUTORADIOBUTTON, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
		}
	}

} //  namespace maxGUI