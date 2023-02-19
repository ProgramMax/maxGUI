// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Frame.hpp>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{
	
	Frame::Frame(HWND window_handle) noexcept
		: ControlWithText(std::move(window_handle))
	{}
	
	HWND Frame::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text) noexcept {
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, WS_CHILD | WS_VISIBLE | BS_GROUPBOX, rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI