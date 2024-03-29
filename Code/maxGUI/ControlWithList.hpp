// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CONTROLWITHLIST_HPP
#define MAXGUI_CONTROLWITHLIST_HPP

#include <string>
#include <vector>

#include <max/Compiling/Configuration.hpp>

#include <maxGUI/Control.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif

namespace maxGUI
{

	class ControlWithList : public Control {
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit ControlWithList(HWND window_handle) noexcept;
#endif

		~ControlWithList() noexcept override = default;

		virtual void OnSelectionChanged(int newly_selected_index) noexcept;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_CONTROLWITHTEXT_HPP