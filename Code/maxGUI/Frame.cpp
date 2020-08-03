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
	
	HWND FrameFactoryImplementationDetails::CreateFrame(std::string text, Rectangle rectangle, HWND parent_window_handle) noexcept {
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, WS_CHILD | WS_VISIBLE | BS_GROUPBOX, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI