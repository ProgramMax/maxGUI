// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_LISTBOX_HPP
#define MAXGUI_LISTBOX_HPP

#include <maxGUI/ControlWithList.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>
#include <vector>

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

		static HWND CreateListBox(Rectangle rectangle, std::vector<std::string> list, HWND parent_window_handle) noexcept;

	};
	
	template <typename ListBoxType = ListBox>
	class ListBoxFactory : public ControlWithListFactory
	{
	public:

		ListBoxFactory(Rectangle rectangle, std::vector<std::string> list) noexcept
			: ControlWithListFactory(std::move(rectangle), std::move(list))
		{}

		~ListBoxFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = ListBoxFactoryImplementationDetails::CreateListBox(rectangle_, list_, std::move(parent_window_handle));
			return std::make_unique<ListBoxType>(std::move(window_handle));
		}

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_LISTBOX_HPP