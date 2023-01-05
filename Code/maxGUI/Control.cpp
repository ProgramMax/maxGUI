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
#elif defined(MAX_PLATFORM_LINUX)
	Control::Control(QWidget* widget) noexcept
		: widget_(std::move(widget))
	{}
#endif

	void Control::Move(Rectangle rectangle) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		SetWindowPos(window_handle_, NULL, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, SWP_NOZORDER);
#endif
#if defined(MAX_PLATFORM_LINUX)
		if (this) {
			widget_->setGeometry(rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_);
		}
#endif
	}

#if defined(MAX_PLATFORM_WINDOWS)
	void Control::OnCommand(WORD /*notification*/) noexcept
	{}
#endif

	ControlFactory::ControlFactory(Rectangle rectangle) noexcept
		: rectangle_(std::move(rectangle))
	{}

} // namespace maxGUI
