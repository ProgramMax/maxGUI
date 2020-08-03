// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_RADIOBUTTON_HPP
#define MAXGUI_RADIOBUTTON_HPP

#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

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

		static HWND CreateRadioButton(std::string text, Rectangle rectangle, HWND parent_window_handle) noexcept;

	};
	
	template <typename RadioButtonType = RadioButton>
	class RadioButtonFactory : public ControlWithTextFactory
	{
	public:

		RadioButtonFactory(Rectangle rectangle, std::string text) noexcept
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
		{}

		~RadioButtonFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = RadioButtonFactoryImplementationDetails::CreateRadioButton(text_, rectangle_, std::move(parent_window_handle));
			return std::make_unique<RadioButtonType>(std::move(window_handle));
		}

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_RADIOBUTTON_HPP