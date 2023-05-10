// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_LISTBOX_HPP
#define MAXGUI_LISTBOX_HPP

#include <string>
#include <vector>

#include <max/Compiling/Bitmask.hpp>
#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithList.hpp>
#include <maxGUI/ListBoxImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

namespace maxGUI
{

	class DefaultListBoxBehavior {
	};

	template< class Behavior = DefaultListBoxBehavior >
	class ListBox : public ControlWithList
	{
	public:

		explicit ListBox(HWND window_handle) noexcept;

		~ListBox() noexcept override;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::vector<std::string> list, ListBoxStyles styles = ListBoxStyles::None) noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

		Behavior behavior_;
		ListBoxImplementation implementation_;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#include <maxGUI/ListBox.inl>

#endif // #ifndef MAXGUI_LISTBOX_HPP