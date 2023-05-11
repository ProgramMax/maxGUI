// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Control.hpp>

#include <utility>

namespace maxGUI
{


#if defined(MAX_PLATFORM_WINDOWS)
	Control::Control(HWND window_handle) noexcept
		: window_handle_(std::move(window_handle))
	{}
#endif

	void Control::Move(max::Containers::Rectangle<int, int> rectangle) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		SetWindowPos(window_handle_, NULL, rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height, SWP_NOZORDER);
#endif
#if defined(MAX_PLATFORM_LINUX)
		(void)rectangle;
#endif
	}

	void Control::NewSystemFont() noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		// Win32 way
		LOGFONT lf = {0};
		SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(lf), &lf, 0);
		HFONT font = CreateFontIndirect(&lf);
		SendMessage(window_handle_, WM_SETFONT, reinterpret_cast<WPARAM>(font), TRUE);

		// WinUI way
		/*
		//const int font_height_in_points = 10; // 14
		//HDC screen_device_context = GetDC(NULL);
		//const int font_height_in_logical_units = -MulDiv(font_height_in_points, GetDeviceCaps(screen_device_context, LOGPIXELSY), 72);
		const int font_height_in_logical_units = -14; // -12
		// Shouldn't it be "Segoe UI Variable"? Why does that look wrong?
		HFONT font = CreateFont(font_height_in_logical_units, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE | DEFAULT_PITCH, TEXT("Segoe UI"));
		SendMessage(window_handle_, WM_SETFONT, reinterpret_cast<WPARAM>(font), TRUE);
		*/
#endif
	}

#if defined(MAX_PLATFORM_WINDOWS)
	void Control::OnCommand(WORD /*notification*/) noexcept
	{}
#endif

} // namespace maxGUI