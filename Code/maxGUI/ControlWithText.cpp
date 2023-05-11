// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ControlWithText.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
#include <maxGUI/Win32String.hpp>
#endif

#include <utility>

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	ControlWithText::ControlWithText(HWND window_handle) noexcept
		: Control(std::move(window_handle))
	{}
#endif

	std::string ControlWithText::GetText() const noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		size_t length_in_chars = static_cast<size_t>(SendMessage(window_handle_, WM_GETTEXTLENGTH, 0, 0)) + 1; // +1 for the null
		TCHAR* buffer = new wchar_t[length_in_chars];
		SendMessage(window_handle_, WM_GETTEXT, length_in_chars, reinterpret_cast<LPARAM>(buffer));
		Win32String win32_string(std::move(buffer), length_in_chars - 1);
		return Win32StringToUtf8(std::move(win32_string));
#endif
#if defined(MAX_PLATFORM_LINUX)
		return std::string();
#endif
	}

	void ControlWithText::SetText(std::string text) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		SendMessage(window_handle_, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(win32_text.text_));
#endif
#if defined(MAX_PLATFORM_LINUX)
		(void)text;
#endif
	}

} // namespace maxGUI