// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_BUTTON_HPP
#define MAXGUI_BUTTON_HPP

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	enum class ButtonStyles {
		None = 1,
		Default = 2,
		Flat = 4,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::ButtonStyles);

namespace maxGUI
{

	class Button : public ControlWithText
	{
	public:

		explicit Button(HWND window_handle) noexcept;

		~Button() noexcept override = default;

		virtual void OnPressed() noexcept = 0;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};
	
	class ButtonFactoryImplementationDetails
	{
	public:

		static HWND CreateButton(std::string text, Rectangle rectangle, ButtonStyles styles, HWND parent_window_handle) noexcept;

	};

	template <typename ButtonType>
	class ButtonFactory : public ControlWithTextFactory
	{
	public:

		ButtonFactory(Rectangle rectangle, std::string text) noexcept
			: ButtonFactory(std::move(rectangle), std::move(text), ButtonStyles::None)
		{}

		ButtonFactory(Rectangle rectangle, std::string text, ButtonStyles styles) noexcept
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
			, styles_(std::move(styles))
		{}

		~ButtonFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = ButtonFactoryImplementationDetails::CreateButton(text_, rectangle_, styles_, std::move(parent_window_handle));
			return std::make_unique<ButtonType>(std::move(window_handle));
		}

		ButtonStyles styles_;

	};


} //  namespace maxGUI

#endif // #ifndef MAXGUI_BUTTON_HPP