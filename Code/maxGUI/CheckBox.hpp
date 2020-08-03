// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CHECKBOX_HPP
#define MAXGUI_CHECKBOX_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	class CheckBox : public ControlWithText
	{
	public:

		explicit CheckBox(HWND window_handle) MAX_DOES_NOT_THROW;

		~CheckBox() MAX_DOES_NOT_THROW override = default;

		virtual void OnPressed() MAX_DOES_NOT_THROW;

		bool IsChecked() const MAX_DOES_NOT_THROW;
		void Check() MAX_DOES_NOT_THROW;
		void Uncheck() MAX_DOES_NOT_THROW;

	//protected:

		void OnCommand(WORD notification) MAX_DOES_NOT_THROW override;

	};
	
	class CheckBoxFactoryImplementationDetails
	{
	public:

		static HWND CreateCheckBox(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW;

	};

	template <typename CheckBoxType = CheckBox>
	class CheckBoxFactory : public ControlWithTextFactory
	{
	public:

		CheckBoxFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
		{}

		~CheckBoxFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override {
			HWND window_handle = CheckBoxFactoryImplementationDetails::CreateCheckBox(text_, rectangle_, std::move(parent_window_handle));
			return std::make_unique<CheckBoxType>(std::move(window_handle));
		}

	};


} //  namespace maxGUI

#endif // #ifndef MAXGUI_BUTTON_HPP