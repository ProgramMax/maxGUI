// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_DROPDOWNBOX_HPP
#define MAXGUI_DROPDOWNBOX_HPP

#include <maxGUI/ControlWithList.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>
#include <vector>

namespace maxGUI
{

	class DropDownBox : public ControlWithList
	{
	public:

		explicit DropDownBox(HWND window_handle) noexcept;

		~DropDownBox() noexcept override = default;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};
	
	class DropDownBoxFactoryImplementationDetails
	{
	public:

		static HWND CreateDropDownBox(Rectangle rectangle, std::vector<std::string> list, HWND parent_window_handle) noexcept;

	};

	template <typename DropDownBoxType = DropDownBox>
	class DropDownBoxFactory : public ControlWithListFactory
	{
	public:

		DropDownBoxFactory(Rectangle rectangle, std::vector<std::string> list) noexcept
			: ControlWithListFactory(std::move(rectangle), std::move(list))
		{}

		~DropDownBoxFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = DropDownBoxFactoryImplementationDetails::CreateDropDownBox(rectangle_, list_, std::move(parent_window_handle));
			return std::make_unique<DropDownBoxType>(std::move(window_handle));
		}

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_DROPDOWNBOX_HPP