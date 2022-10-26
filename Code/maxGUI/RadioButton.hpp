// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_RADIOBUTTON_HPP
#define MAXGUI_RADIOBUTTON_HPP


#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	enum class RadioButtonStyles : uint8_t {
		None = 0,
		Disabled = 1,
		FirstInGroup = 2,
		Flat = 4,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::RadioButtonStyles);

namespace maxGUI
{

	class RadioButton : public ControlWithText
	{
	public:

		explicit RadioButton(HWND window_handle) noexcept;

		~RadioButton() noexcept override = default;

		virtual void OnPressed() noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};

	class RadioButtonFactoryImplementationDetails
	{
	public:

		static HWND CreateRadioButton(std::string text, Rectangle rectangle, RadioButtonStyles styles, HWND parent_window_handle) noexcept;

	};
	
	template <typename RadioButtonType = RadioButton>
	class RadioButtonFactory : public ControlWithTextFactory
	{
	public:

		RadioButtonFactory(Rectangle rectangle, std::string text) noexcept
			: RadioButtonFactory(std::move(rectangle), std::move(text), RadioButtonStyles::None)
		{}

		RadioButtonFactory(Rectangle rectangle, std::string text, RadioButtonStyles styles) noexcept
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
			, styles_(std::move(styles))
		{}

		~RadioButtonFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = RadioButtonFactoryImplementationDetails::CreateRadioButton(text_, rectangle_, styles_, std::move(parent_window_handle));
			return std::make_unique<RadioButtonType>(std::move(window_handle));
		}

	private:

		RadioButtonStyles styles_;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_RADIOBUTTON_HPP