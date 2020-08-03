// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Control.hpp>

#include <utility>

namespace maxGUI
{

	Control::Control(HWND window_handle) noexcept
		: window_handle_(std::move(window_handle))
	{}

	void Control::Move(Rectangle rectangle) noexcept {
		SetWindowPos(window_handle_, NULL, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, SWP_NOZORDER);
	}

	void Control::OnCommand(WORD /*notification*/) noexcept
	{}

	ControlFactory::ControlFactory(Rectangle rectangle) noexcept
		: rectangle_(std::move(rectangle))
	{}

} // namespace maxGUI