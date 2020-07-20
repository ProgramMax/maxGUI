// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_BUTTON_HPP
#define MAXGUI_BUTTON_HPP

#include <maxGUI/Control.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <max/Compiling/ThrowSpecification.hpp>

namespace maxGUI
{

	class Button : public Control
	{
	public:

		explicit Button(HWND window_handle) MAX_DOES_NOT_THROW;

		~Button() MAX_DOES_NOT_THROW override = default;

		virtual void OnPressed() MAX_DOES_NOT_THROW;

	//protected:

		void OnCommand(WORD notification) MAX_DOES_NOT_THROW override;

	};
	
	class ButtonFactory : public ControlFactory
	{
	public:

		ButtonFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW;

		~ButtonFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override;

	//private:

		Rectangle rectangle_;
		std::string text_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_BUTTON_HPP