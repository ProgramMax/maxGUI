// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CONTROLWITHTEXT_HPP
#define MAXGUI_CONTROLWITHTEXT_HPP

#include <max/Compiling/Configuration.hpp>
#include <maxGUI/Control.hpp>
#include <string>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
	#endif
	#include <Windows.h>
#endif

namespace maxGUI
{

	class ControlWithText : public Control {
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit ControlWithText(HWND window_handle) noexcept;
#endif

		~ControlWithText() noexcept override = default;

		std::string GetText() const noexcept;
		void SetText(std::string text) noexcept;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_CONTROLWITHTEXT_HPP