// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/CheckBoxImplementation.hpp>

#include <utility>

#if defined(MAX_PLATFORM_WINDOWS)
	#include <maxGUI/Win32String.hpp>
#endif

namespace maxGUI
{

	CheckBoxImplementation::CheckBoxImplementation(HWND window_handle) noexcept
		: ControlWithTextImplementation(std::move(window_handle))
	{}

	CheckBoxImplementation::~CheckBoxImplementation() noexcept = default;

#if defined(MAX_PLATFORM_WINDOWS)
	HWND CheckBoxImplementation::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, CheckBoxStyles styles) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_CHECKBOX | BS_NOTIFY;
		// MSVC at warning level 4 issues C26813 because it wants "if (styles & ButtonStyles::Default) {"
		// But this doesn't play nicely with enum classes because ultimately it needs to convert to bool.
		// See https://developercommunity.visualstudio.com/t/C26813-incompatible-with-enum-class/10145182
#pragma warning(push)
#pragma warning(disable: 26813)
		if ((styles & CheckBoxStyles::Disabled) == CheckBoxStyles::Disabled) {
			win32_styles |= WS_DISABLED;
		}
		if ((styles & CheckBoxStyles::Flat) == CheckBoxStyles::Flat) {
			win32_styles |= BS_FLAT;
		}
#pragma warning(pop)
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		//return CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, win32_styles, rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
		HWND window_handle = CreateWindowEx(0, TEXT("BUTTON"), win32_text.text_, win32_styles, rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);

		/*
		LOGFONT lf;
		SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(lf), &lf, 0);
		HFONT font = CreateFontIndirect(&lf);
		*/

		const int font_height_in_points = 10;
		HDC screen_device_context = GetDC(NULL);
		const int font_height_in_logical_units = -MulDiv(font_height_in_points, GetDeviceCaps(screen_device_context, LOGPIXELSY), 72);
		//const int font_height_in_logical_units = -12;
		HFONT font = CreateFont(font_height_in_logical_units, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE | DEFAULT_PITCH, TEXT("Segoe UI"));

		SendMessage(window_handle, WM_SETFONT, reinterpret_cast<WPARAM>(font), TRUE);

		return window_handle;
	}

	bool CheckBoxImplementation::IsChecked() const noexcept {
		return SendMessage(window_handle_, BM_GETCHECK, 0, 0) == BST_CHECKED;
	}

	void CheckBoxImplementation::Check() noexcept {
		SendMessage(window_handle_, BM_SETCHECK, BST_CHECKED, 0);
	}

	void CheckBoxImplementation::Uncheck() noexcept {
		SendMessage(window_handle_, BM_SETCHECK, BST_UNCHECKED, 0);
	}

#endif

} // namespace maxGUI