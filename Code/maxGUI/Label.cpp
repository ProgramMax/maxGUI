// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Label.hpp>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{
	
	Label::Label(HWND window_handle) MAX_DOES_NOT_THROW
		: ControlWithText(std::move(window_handle))
	{}

	HWND LabelFactoryImplementationDetails::CreateLabel(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW {
		// TODO: Probably specify WS_EX_TRANSPARENT and handle WM_ERASEBKGND...no one actually wants the non-transparent background
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(0, TEXT("STATIC"), win32_text.text_, WS_CHILD | WS_VISIBLE, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI