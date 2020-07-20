// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Win32String.hpp>

#include <utility>

namespace maxGUI {

	Win32String::Win32String(LPTSTR text, size_t char_count) MAX_DOES_NOT_THROW
		: text_(std::move(text))
		, char_count_(std::move(char_count))
	{}

	Win32String::Win32String(Win32String&& other) MAX_DOES_NOT_THROW
		: text_(std::move(other.text_))
		, char_count_(std::move(other.char_count_))
	{
		other.text_ = nullptr;
	}

	Win32String::~Win32String() MAX_DOES_NOT_THROW
	{
		delete[] text_;
	}

	Win32String& Win32String::operator =(Win32String&& other) MAX_DOES_NOT_THROW {
		delete[] text_;

		text_ = std::move(other.text_);
		char_count_ = std::move(other.char_count_);

		other.text_ = nullptr;

		return *this;
	}

	Win32String Utf8ToWin32String(std::string text) MAX_DOES_NOT_THROW {
		#if defined(UNICODE)
			int wide_char_count = MultiByteToWideChar(CP_UTF8, 0, text.c_str(), -1, nullptr, 0);
			wchar_t* wide_string = new wchar_t[wide_char_count];
			MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, text.c_str(), -1, wide_string, wide_char_count);

			return Win32String(wide_string, wide_char_count);
		#else
			#error "TODO: Implement non-wide version"
		#endif
	}

	std::string Win32StringToUtf8(Win32String text) MAX_DOES_NOT_THROW {
		#if defined(UNICODE)
		int utf8_char_count = WideCharToMultiByte(CP_UTF8, 0, text.text_, text.char_count_, nullptr, 0, nullptr, nullptr);
		std::string utf8_string(utf8_char_count, '\0');
		WideCharToMultiByte(CP_UTF8, 0, text.text_, text.char_count_, &utf8_string[0], utf8_char_count, nullptr, nullptr);
		return utf8_string;
		#else
			#error "TODO: Implement non-wide version"
		#endif
	}

} // namespace maxGUI