// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_DROPDOWNBOXIMPLEMENTATION_HPP
#define MAXGUI_DROPDOWNBOXIMPLEMENTATION_HPP

#include <string>
#include <vector>

#include <max/Compiling/Bitmask.hpp>
#include <max/Containers/Rectangle.hpp>
#include <max/Compiling/Configuration.hpp>
#include <maxGUI/ControlWithTextImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif

namespace maxGUI
{

	enum class DropDownBoxStyles : uint8_t {
		None = 0,
		Disabled = 1,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::DropDownBoxStyles);

namespace maxGUI
{

	class DropDownBoxImplementation : public ControlWithTextImplementation
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit DropDownBoxImplementation(HWND window_handle) noexcept;
#endif

		~DropDownBoxImplementation() noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::vector<std::string> list, DropDownBoxStyles styles) noexcept;
#endif

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_DROPDOWNBOXIMPLEMENTATION_HPP