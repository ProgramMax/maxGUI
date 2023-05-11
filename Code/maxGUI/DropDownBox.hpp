// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_DROPDOWNBOX_HPP
#define MAXGUI_DROPDOWNBOX_HPP

#include <string>
#include <vector>

#include <max/Compiling/Configuration.hpp>
#include <max/Compiling/Bitmask.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithList.hpp>
#include <maxGUI/DropDownBoxImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

namespace maxGUI
{

	class DefaultDropDownBoxBehavior {
	};

	template< class Behavior = DefaultDropDownBoxBehavior >
	class DropDownBox : public ControlWithList
	{
	public:

		explicit DropDownBox(HWND window_handle) noexcept;

		~DropDownBox() noexcept override;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::vector<std::string> list, DropDownBoxStyles styles = DropDownBoxStyles::None) noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	private:

		Behavior behavior_;
		DropDownBoxImplementation implementation_;

	};
	
} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#include <maxGUI/DropDownBox.inl>

#endif // #ifndef MAXGUI_DROPDOWNBOX_HPP