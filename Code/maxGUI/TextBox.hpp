// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_TEXTBOX_HPP
#define MAXGUI_TEXTBOX_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	class TextBox : public ControlWithText
	{
	public:

		explicit TextBox(HWND window_handle) MAX_DOES_NOT_THROW;

		~TextBox() MAX_DOES_NOT_THROW override = default;

	};

	class TextBoxFactoryImplementationDetails
	{
	public:

		static HWND CreateTextBox(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW;

	};

	template <typename TextBoxType = TextBox>
	class TextBoxFactory : public ControlWithTextFactory
	{
	public:

		TextBoxFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
		{}

		~TextBoxFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override {
			HWND window_handle = TextBoxFactoryImplementationDetails::CreateTextBox(text_, rectangle_, std::move(parent_window_handle));
			return std::make_unique<TextBoxType>(std::move(window_handle));
		}

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_TEXTBOX_HPP