// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_LISTBOX_HPP
#define MAXGUI_LISTBOX_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/Control.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>
#include <vector>

namespace maxGUI
{

	class ListBox : public Control
	{
	public:

		explicit ListBox(HWND window_handle) MAX_DOES_NOT_THROW;

		~ListBox() MAX_DOES_NOT_THROW override = default;

	};

	class ListBoxFactoryImplementationDetails
	{
	public:

		static HWND CreateListBox(Rectangle rectangle, std::vector<std::string> list, HWND parent_window_handle) MAX_DOES_NOT_THROW;

	};
	
	template <typename ListBoxType = ListBox>
	class ListBoxFactory : public ControlFactory
	{
	public:

		ListBoxFactory(Rectangle rectangle, std::vector<std::string> list) MAX_DOES_NOT_THROW
			: ControlFactory(std::move(rectangle))
			, list_(std::move(list))
		{}

		~ListBoxFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override {
			HWND window_handle = ListBoxFactoryImplementationDetails::CreateListBox(rectangle_, list_, std::move(parent_window_handle));
			return std::make_unique<ListBoxType>(std::move(window_handle));
		}

	//private:

		std::vector<std::string> list_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_LISTBOX_HPP