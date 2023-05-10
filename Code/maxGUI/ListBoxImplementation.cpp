// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ListBoxImplementation.hpp>

#include <utility>

#if defined(MAX_PLATFORM_WINDOWS)
	#include <maxGUI/Win32String.hpp>
#endif

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	ListBoxImplementation::ListBoxImplementation(HWND window_handle) noexcept
		: ControlWithTextImplementation(std::move(window_handle))
	{}
#endif

	ListBoxImplementation::~ListBoxImplementation() noexcept = default;

#if defined(MAX_PLATFORM_WINDOWS)
	HWND ListBoxImplementation::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::vector<std::string> list, ListBoxStyles styles) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_TABSTOP | LBS_STANDARD;
		// MSVC at warning level 4 issues C26813 because it wants "if (styles & ButtonStyles::Default) {"
		// But this doesn't play nicely with enum classes because ultimately it needs to convert to bool.
		// See https://developercommunity.visualstudio.com/t/C26813-incompatible-with-enum-class/10145182
#pragma warning(push)
#pragma warning(disable: 26813)
		if ((styles & ListBoxStyles::Disabled) == ListBoxStyles::Disabled) {
			win32_styles |= WS_DISABLED;
		}
		if ((styles & ListBoxStyles::SingleClickMultipleSelection) == ListBoxStyles::SingleClickMultipleSelection) {
			win32_styles |= LBS_MULTIPLESEL;
		}
		if ((styles & ListBoxStyles::KeyboardAndClickMultipleSelection) == ListBoxStyles::KeyboardAndClickMultipleSelection) {
			win32_styles |= LBS_EXTENDEDSEL;
		}
#pragma warning(pop)
		HWND window_handle = CreateWindowEx(0, TEXT("LISTBOX"), TEXT(""), win32_styles, rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);

		for (const auto& text : list) {
			Win32String win32_text = Utf8ToWin32String(text);
			SendMessage(window_handle, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>(win32_text.text_));
		}

		return window_handle;
	}
#endif

} // namespace maxGUI