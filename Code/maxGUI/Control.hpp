// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CONTROL_HPP
#define MAXGUI_CONTROL_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/Rectangle.hpp>
#include <memory>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

namespace maxGUI
{

	class Control {
	public:

		explicit Control(HWND window_handle) MAX_DOES_NOT_THROW;

		virtual ~Control() MAX_DOES_NOT_THROW = default;

		void Move(Rectangle rectangle) MAX_DOES_NOT_THROW;

		HWND window_handle_;

	//protected:

		virtual void OnCommand(WORD notification) MAX_DOES_NOT_THROW;

	};

	class ControlFactory {
	public:

		ControlFactory(Rectangle rectangle) MAX_DOES_NOT_THROW;

		virtual ~ControlFactory() MAX_DOES_NOT_THROW = default;

		virtual std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW = 0;

		Rectangle rectangle_;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_CONTROL_HPP