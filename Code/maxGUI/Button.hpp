// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_BUTTON_HPP
#define MAXGUI_BUTTON_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	class Button : public ControlWithText
	{
	public:

		explicit Button(HWND window_handle) MAX_DOES_NOT_THROW;

		~Button() MAX_DOES_NOT_THROW override = default;

		virtual void OnPressed() MAX_DOES_NOT_THROW = 0;

	//protected:

		void OnCommand(WORD notification) MAX_DOES_NOT_THROW override;

	};
	
	class ButtonFactoryImplementationDetails
	{
	public:

		static HWND CreateButton(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW;

	};

	template <typename ButtonType>
	class ButtonFactory : public ControlWithTextFactory
	{
	public:

		ButtonFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
		{}

		~ButtonFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override {
			HWND window_handle = ButtonFactoryImplementationDetails::CreateButton(text_, rectangle_, std::move(parent_window_handle));
			return std::make_unique<ButtonType>(std::move(window_handle));
		}

	};


} //  namespace maxGUI

#endif // #ifndef MAXGUI_BUTTON_HPP