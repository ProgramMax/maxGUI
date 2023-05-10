// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CONTROLIMPLEMENTATION_HPP
#define MAXGUI_CONTROLIMPLEMENTATION_HPP

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAD_AND_MEAN
	#endif

	#include <Windows.h>
#endif

namespace maxGUI
{

	class ControlImplementation
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		ControlImplementation(HWND window_handle) noexcept;
#endif

		virtual ~ControlImplementation() noexcept;

	//private:

		HWND window_handle_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_CONTROLIMPLEMENTATION_HPP
