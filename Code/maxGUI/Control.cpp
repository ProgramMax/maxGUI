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

#if defined(MAX_PLATFORM_WINDOWS)
	void Control::OnCommand(WORD /*notification*/) noexcept
	{}
#endif

} // namespace maxGUI