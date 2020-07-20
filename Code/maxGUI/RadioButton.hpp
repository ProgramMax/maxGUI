// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_RADIOBUTTON_HPP
#define MAXGUI_RADIOBUTTON_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	class RadioButton : public ControlWithText
	{
	public:

		explicit RadioButton(HWND window_handle) MAX_DOES_NOT_THROW;

		~RadioButton() MAX_DOES_NOT_THROW override = default;

		virtual void OnPressed() MAX_DOES_NOT_THROW;

	//protected:

		void OnCommand(WORD notification) MAX_DOES_NOT_THROW override;

	};

	class RadioButtonFactoryImplementationDetails
	{
	public:

		static HWND CreateRadioButton(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW;

	};
	
	template <typename RadioButtonType = RadioButton>
	class RadioButtonFactory : public ControlWithTextFactory
	{
	public:

		RadioButtonFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
		{}

		~RadioButtonFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override {
			HWND window_handle = RadioButtonFactoryImplementationDetails::CreateRadioButton(text_, rectangle_, std::move(parent_window_handle));
			return std::make_unique<RadioButtonType>(std::move(window_handle));
		}

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_RADIOBUTTON_HPP