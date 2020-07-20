// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_WIN32STRING_HPP
#define MAXGUI_WIN32STRING_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <string>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

namespace maxGUI {

	// TODO: Add allocator / deallocator
	class Win32String {
	public:

		Win32String(LPTSTR text, size_t char_count) MAX_DOES_NOT_THROW;
		Win32String(const Win32String&) = default;
		Win32String(Win32String&& other) MAX_DOES_NOT_THROW;
		~Win32String() MAX_DOES_NOT_THROW;

		Win32String& operator =(const Win32String&) = default;
		Win32String& operator =(Win32String&& other) MAX_DOES_NOT_THROW;

		LPTSTR text_;
		size_t char_count_;

	};

	Win32String Utf8ToWin32String(std::string text) MAX_DOES_NOT_THROW;
	std::string Win32StringToUtf8(Win32String text) MAX_DOES_NOT_THROW;

} // namespace maxGUI

#endif // #ifndef MAXGUI_WIN32STRING_HPP