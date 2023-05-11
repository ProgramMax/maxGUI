// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CHECKBOX_HPP
#define MAXGUI_CHECKBOX_HPP

#include <string>

#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/CheckBoxImplementation.hpp>
#include <maxGUI/ControlWithText.hpp>


#if defined(MAX_PLATFORM_WINDOWS)

namespace maxGUI
{

	class DefaultCheckBoxBehavior {
	};

	template< class Behavior = DefaultCheckBoxBehavior >
	class CheckBox : public ControlWithText
	{
	public:

		explicit CheckBox(HWND window_handle) noexcept;

		~CheckBox() noexcept override;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, CheckBoxStyles styles = CheckBoxStyles::None) noexcept;

		virtual void OnPressed() noexcept;

		bool IsChecked() const noexcept;
		void Check() noexcept;
		void Uncheck() noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	private:

		Behavior behavior_;
		CheckBoxImplementation implementation_;

	};
	
} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#include <maxGUI/CheckBox.inl>

#endif // #ifndef MAXGUI_BUTTON_HPP