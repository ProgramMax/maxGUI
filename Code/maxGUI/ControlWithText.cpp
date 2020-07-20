// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ControlWithText.hpp>

#include <maxGUI/Win32String.hpp>
#include <utility>

namespace maxGUI
{

	ControlWithText::ControlWithText(HWND window_handle) MAX_DOES_NOT_THROW
		: Control(std::move(window_handle))
	{}

	std::string ControlWithText::GetText() const MAX_DOES_NOT_THROW {
		LRESULT length_in_chars = SendMessage(window_handle_, WM_GETTEXTLENGTH, 0, 0);
		TCHAR* buffer = new wchar_t[length_in_chars];
		SendMessage(window_handle_, WM_GETTEXT, length_in_chars, reinterpret_cast<LPARAM>(buffer));
		Win32String win32_string(std::move(buffer), std::move(length_in_chars));
		return Win32StringToUtf8(std::move(win32_string));
	}

	void ControlWithText::SetText(std::string text) MAX_DOES_NOT_THROW {
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		SendMessage(window_handle_, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(win32_text.text_));
	}

	ControlWithTextFactory::ControlWithTextFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW
		: ControlFactory(std::move(rectangle))
		, text_(std::move(text))
	{}

} // namespace maxGUI