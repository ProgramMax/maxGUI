// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ButtonImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#include <maxGUI/Win32String.hpp>
#endif

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	ButtonImplementation::ButtonImplementation(HWND window_handle) noexcept
		: ControlWithTextImplementation(std::move(window_handle))
	{}
#endif

	ButtonImplementation::~ButtonImplementation() noexcept = default;

#if defined(MAX_PLATFORM_WINDOWS)
	HWND ButtonImplementation::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, ButtonStyles styles) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_NOTIFY;
		// MSVC at warning level 4 issues C26813 because it wants "if (styles & ButtonStyles::Default) {"
		// But this doesn't play nicely with enum classes because ultimately it needs to convert to bool.
		// See https://developercommunity.visualstudio.com/t/C26813-incompatible-with-enum-class/10145182
#pragma warning(push)
#pragma warning(disable: 26813)
		if ((styles & ButtonStyles::Disabled) == ButtonStyles::Disabled) {
			win32_styles |= WS_DISABLED;
		}
		if ((styles & ButtonStyles::Default) == ButtonStyles::Default) {
			win32_styles |= BS_DEFPUSHBUTTON;
		}
		if ((styles & ButtonStyles::Flat) == ButtonStyles::Flat) {
			win32_styles |= BS_FLAT;
		}
#pragma warning(pop)

		Win32String win32_text = Utf8ToWin32String(std::move(text));

		return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, win32_styles, rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}
#endif

} // namespace maxGUI