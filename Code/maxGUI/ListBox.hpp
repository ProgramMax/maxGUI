// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_LISTBOX_HPP
#define MAXGUI_LISTBOX_HPP

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <max/Compiling/Bitmask.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithList.hpp>
#include <string>
#include <utility>
#include <vector>

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

	class ListBox : public ControlWithList
	{
	public:

		explicit ListBox(HWND window_handle) noexcept;

		~ListBox() noexcept override = default;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::vector<std::string> list, ListBoxStyles styles = ListBoxStyles::None) noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_LISTBOX_HPP