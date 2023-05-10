// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CONTROLWITHTEXTIMPLEMENTATION_HPP
#define MAXGUI_CONTROLWITHTEXTIMPLEMENTATION_HPP

#include <string>

#include <max/Compiling/Configuration.hpp>
#include <maxGUI/ControlImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif


namespace maxGUI
{

	class ControlWithTextImplementation : public ControlImplementation
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		ControlWithTextImplementation(HWND window_handle) noexcept;
#endif

		~ControlWithTextImplementation() noexcept override;

		std::string GetText() const noexcept;
		void SetText(std::string text) noexcept;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_CONTROLWITHTEXTIMPLEMENTATION_HPP