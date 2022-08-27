// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CHECKBOX_HPP
#define MAXGUI_CHECKBOX_HPP

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	enum class CheckBoxStyles : uint8_t {
		None = 0,
		Flat = 1,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::CheckBoxStyles);

namespace maxGUI
{

	class CheckBox : public ControlWithText
	{
	public:

		explicit CheckBox(HWND window_handle) noexcept;

		~CheckBox() noexcept override = default;

		virtual void OnPressed() noexcept;

		bool IsChecked() const noexcept;
		void Check() noexcept;
		void Uncheck() noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};
	
	class CheckBoxFactoryImplementationDetails
	{
	public:

		static HWND CreateCheckBox(std::string text, Rectangle rectangle, CheckBoxStyles styles, HWND parent_window_handle) noexcept;

	};

	template <typename CheckBoxType = CheckBox>
	class CheckBoxFactory : public ControlWithTextFactory
	{
	public:

		CheckBoxFactory(Rectangle rectangle, std::string text) noexcept
			: CheckBoxFactory(std::move(rectangle), std::move(text), CheckBoxStyles::None)
		{}

		CheckBoxFactory(Rectangle rectangle, std::string text, CheckBoxStyles styles) noexcept
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
			, styles_(std::move(styles))
		{}

		~CheckBoxFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = CheckBoxFactoryImplementationDetails::CreateCheckBox(text_, rectangle_, styles_, std::move(parent_window_handle));
			return std::make_unique<CheckBoxType>(std::move(window_handle));
		}

	private:

		CheckBoxStyles styles_;

	};


} //  namespace maxGUI

#endif // #ifndef MAXGUI_BUTTON_HPP