// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Control.hpp>

#include <utility>

namespace maxGUI
{

	Control::Control(HWND window_handle) MAX_DOES_NOT_THROW
		: window_handle_(std::move(window_handle))
	{}

	void Control::Move(int left, int top, int width, int height) MAX_DOES_NOT_THROW {
		SetWindowPos(window_handle_, NULL, left, top, width, height, SWP_NOZORDER);
	}

	void Control::OnCommand(WORD /*notification*/) MAX_DOES_NOT_THROW
	{}

	ControlFactory::~ControlFactory() MAX_DOES_NOT_THROW
	{}

} // namespace maxGUI