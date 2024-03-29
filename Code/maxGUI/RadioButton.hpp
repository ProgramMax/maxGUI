// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_RADIOBUTTON_HPP
#define MAXGUI_RADIOBUTTON_HPP

#include <string>

#include <max/Compiling/Bitmask.hpp>
#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/RadioButtonImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

namespace maxGUI
{

	class DefaultRadioButtonBehavior {
	};

	template< class Behavior = DefaultRadioButtonBehavior >
	class RadioButton : public ControlWithText
	{
	public:

		explicit RadioButton(HWND window_handle) noexcept;

		~RadioButton() noexcept override;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, RadioButtonStyles styles = RadioButtonStyles::None) noexcept;

		virtual void OnPressed() noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	private:

		Behavior behavior_;
		RadioButtonImplementation implementation_;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#include <maxGUI/RadioButton.inl>

#endif // #ifndef MAXGUI_RADIOBUTTON_HPP