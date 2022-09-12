// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_DROPDOWNBOX_HPP
#define MAXGUI_DROPDOWNBOX_HPP

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

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};
	
	class DropDownBoxFactoryImplementationDetails
	{
	public:

		static HWND CreateDropDownBox(Rectangle rectangle, std::vector<std::string> list, DropDownBoxStyles styles, HWND parent_window_handle) noexcept;

	};

	template <typename DropDownBoxType = DropDownBox>
	class DropDownBoxFactory : public ControlWithListFactory
	{
	public:

		DropDownBoxFactory(Rectangle rectangle, std::vector<std::string> list) noexcept
			: DropDownBoxFactory(std::move(rectangle), std::move(list), DropDownBoxStyles::None)
		{}

		DropDownBoxFactory(Rectangle rectangle, std::vector<std::string> list, DropDownBoxStyles styles) noexcept
			: ControlWithListFactory(std::move(rectangle), std::move(list))
			, styles_(std::move(styles))
		{}

		~DropDownBoxFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = DropDownBoxFactoryImplementationDetails::CreateDropDownBox(rectangle_, list_, styles_, std::move(parent_window_handle));
			return std::make_unique<DropDownBoxType>(std::move(window_handle));
		}

	private:

		DropDownBoxStyles styles_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_DROPDOWNBOX_HPP