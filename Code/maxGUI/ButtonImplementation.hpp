// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_BUTTONIMPLEMENTATION_HPP
#define MAXGUI_BUTTONIMPLEMENTATION_HPP

#include <string>

#include <max/Compiling/Bitmask.hpp>
#include <max/Containers/Rectangle.hpp>
#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif

#include <maxGUI/ControlWithTextImplementation.hpp>

namespace maxGUI
{

	enum class ButtonStyles : uint8_t {
		None = 0,
		Disabled = 1,
		Default = 2,
		Flat = 4,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::ButtonStyles);

namespace maxGUI
{

	class ButtonImplementation : public ControlWithTextImplementation
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit ButtonImplementation(HWND window_handle) noexcept;
#endif

		~ButtonImplementation() noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, ButtonStyles styles) noexcept;
#endif

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_BUTTONIMPLEMENTATION_HPP