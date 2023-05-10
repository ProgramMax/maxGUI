// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_LISTBOXIMPLEMENTATION_HPP
#define MAXGUI_LISTBOXIMPLEMENTATION_HPP

#include <string>
#include <vector>

#include <max/Compiling/Bitmask.hpp>
#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithTextImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif

namespace maxGUI
{

	enum class ListBoxStyles : uint8_t {
		None = 0,
		Disabled = 1,
		SingleClickMultipleSelection = 2,
		KeyboardAndClickMultipleSelection = 4,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::ListBoxStyles);

namespace maxGUI
{

	class ListBoxImplementation : public ControlWithTextImplementation
	{
	public:

		explicit ListBoxImplementation(HWND window_handle) noexcept;

		~ListBoxImplementation() noexcept;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::vector<std::string> list, ListBoxStyles styles) noexcept;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_LISTBOXIMPLEMENTATION_HPP