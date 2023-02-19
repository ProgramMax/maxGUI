// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_DROPDOWNBOX_HPP
#define MAXGUI_DROPDOWNBOX_HPP

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithList.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>
#include <vector>

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
	class DropDownBox : public ControlWithList
	{
	public:

		explicit DropDownBox(HWND window_handle) noexcept;

		~DropDownBox() noexcept override = default;

		static HWND Create(HWND parent_window_handle, Rectangle rectangle, std::vector<std::string> list, DropDownBoxStyles styles = DropDownBoxStyles::None) noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};
	
} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_DROPDOWNBOX_HPP