// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_TEXTBOX_HPP
#define MAXGUI_TEXTBOX_HPP

#include <string>

#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/TextBoxImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

namespace maxGUI
{

	class DefaultTextBoxBehavior {
	};

	template< class Behavior = DefaultTextBoxBehavior >
	class TextBox : public ControlWithText
	{
	public:

		explicit TextBox(HWND window_handle) noexcept;

		~TextBox() noexcept override;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, TextBoxStyles styles = TextBoxStyles::None) noexcept;

		//protected:

#if defined(MAX_PLATFORM_WINDOWS)
		void OnCommand(WORD notification) noexcept override;
#endif

		Behavior behavior_;
		TextBoxImplementation implementation_;

	};

} //  namespace maxGUI

#endif

#include <maxGUI/TextBox.inl>

#endif // #ifndef MAXGUI_TEXTBOX_HPP