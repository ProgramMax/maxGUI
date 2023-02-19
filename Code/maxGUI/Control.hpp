// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CONTROL_HPP
#define MAXGUI_CONTROL_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
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

		void Move(max::Containers::Rectangle<int, int> rectangle) noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
		HWND window_handle_;
#endif

	//protected:

#if defined(MAX_PLATFORM_WINDOWS)
		virtual void OnCommand(WORD notification) noexcept;
#endif

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_CONTROL_HPP
