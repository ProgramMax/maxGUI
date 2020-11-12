// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_LISTBOX_HPP
#define MAXGUI_LISTBOX_HPP

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithList.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>
#include <vector>

namespace maxGUI
{

	enum class ListBoxStyles {
		None = 0,
		SingleClickMultipleSelection = 1,
		KeyboardAndClickMultipleSelection = 2,
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

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};

	class ListBoxFactoryImplementationDetails
	{
	public:

		static HWND CreateListBox(Rectangle rectangle, std::vector<std::string> list, ListBoxStyles styles, HWND parent_window_handle) noexcept;

	};
	
	template <typename ListBoxType = ListBox>
	class ListBoxFactory : public ControlWithListFactory
	{
	public:

		ListBoxFactory(Rectangle rectangle, std::vector<std::string> list) noexcept
			: ListBoxFactory(std::move(rectangle), std::move(list), ListBoxStyles::None)
		{}

		ListBoxFactory(Rectangle rectangle, std::vector<std::string> list, ListBoxStyles styles) noexcept
			: ControlWithListFactory(std::move(rectangle), std::move(list))
			, styles_(std::move(styles))
		{}

		~ListBoxFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = ListBoxFactoryImplementationDetails::CreateListBox(rectangle_, list_, styles_, std::move(parent_window_handle));
			return std::make_unique<ListBoxType>(std::move(window_handle));
		}

	private:

		ListBoxStyles styles_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_LISTBOX_HPP