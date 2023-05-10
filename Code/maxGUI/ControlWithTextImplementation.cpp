// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ControlWithTextImplementation.hpp>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{

	ControlWithTextImplementation::ControlWithTextImplementation(HWND window_handle) noexcept
		: ControlImplementation(std::move(window_handle))
	{}

	ControlWithTextImplementation::~ControlWithTextImplementation() noexcept = default;

	std::string ControlWithTextImplementation::GetText() const noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		size_t length_in_chars = static_cast<size_t>(SendMessage(window_handle_, WM_GETTEXTLENGTH, 0, 0)) + 1; // +1 for the null terminator
		TCHAR* buffer = new wchar_t[length_in_chars];
		SendMessage(window_handle_, WM_GETTEXT, length_in_chars, reinterpret_cast<LPARAM>(buffer));
		Win32String win32_string(std::move(buffer), length_in_chars - 1);
		return Win32StringToUtf8(std::move(win32_string));
#endif
#if defined(MAX_PLATFORM_LINUX)
		return std::string();
#endif
	}

	void ControlWithTextImplementation::SetText(std::string text) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		SendMessage(window_handle_, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(win32_text.text_));
#endif
#if defined(MAX_PLATFORM_LINUX)
		(void)text;
#endif
	}

} // namespace maxGUI