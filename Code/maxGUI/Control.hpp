// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CONTROL_HPP
#define MAXGUI_CONTROL_HPP

#include <max/Compiling/Configuration.hpp>
#include <maxGUI/Rectangle.hpp>
#include <memory>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
	#endif
	#include <Windows.h>
#elif defined(MAX_PLATFORM_LINUX)
	#include <QWidget>
#endif

namespace maxGUI
{

	class Control {
	public:


#if defined(MAX_PLATFORM_WINDOWS)
		explicit Control(HWND window_handle) noexcept;
#endif

		virtual ~Control() noexcept = default;

		void Move(Rectangle rectangle) noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
		HWND window_handle_;
#endif

	//protected:

#if defined(MAX_PLATFORM_WINDOWS)
		virtual void OnCommand(WORD notification) noexcept;
#endif

	};

	class ControlFactory {
	public:

		ControlFactory(Rectangle rectangle) noexcept;

		virtual ~ControlFactory() noexcept = default;


#if defined(MAX_PLATFORM_WINDOWS)
		virtual std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept = 0;
#elif defined(MAX_PLATFORM_LINUX)
		virtual std::unique_ptr<Control> CreateControl(QWidget* parent_window) const noexcept = 0;
#endif

		Rectangle rectangle_;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_CONTROL_HPP
