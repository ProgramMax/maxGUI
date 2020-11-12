// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_TEXTBOX_HPP
#define MAXGUI_TEXTBOX_HPP

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	enum class TextBoxStyles {
		None = 0,
		Password = 1,
		ReadOnly = 2,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::TextBoxStyles);

namespace maxGUI
{

	class TextBox : public ControlWithText
	{
	public:

		explicit TextBox(HWND window_handle) noexcept;

		~TextBox() noexcept override = default;

	};

	class TextBoxFactoryImplementationDetails
	{
	public:

		static HWND CreateTextBox(std::string text, Rectangle rectangle, TextBoxStyles styles, HWND parent_window_handle) noexcept;

	};

	template <typename TextBoxType = TextBox>
	class TextBoxFactory : public ControlWithTextFactory
	{
	public:

		TextBoxFactory(Rectangle rectangle, std::string text) noexcept
			: TextBoxFactory(std::move(rectangle), std::move(text), TextBoxStyles::None)
		{}

		TextBoxFactory(Rectangle rectangle, std::string text, TextBoxStyles styles) noexcept
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
			, styles_(std::move(styles))
		{}

		~TextBoxFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = TextBoxFactoryImplementationDetails::CreateTextBox(text_, rectangle_, styles_, std::move(parent_window_handle));
			return std::make_unique<TextBoxType>(std::move(window_handle));
		}

	private:

		TextBoxStyles styles_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_TEXTBOX_HPP