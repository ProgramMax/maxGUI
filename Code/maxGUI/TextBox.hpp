// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_TEXTBOX_HPP
#define MAXGUI_TEXTBOX_HPP

#include <max/Compiling/Bitmask.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <string>
#include <utility>


#include <max/Compiling/Configuration.hpp>

// TODO: Add Linux version of TextBox
#if defined(MAX_PLATFORM_WINDOWS)

namespace maxGUI
{

	enum class TextBoxStyles : uint8_t {
		None = 0,
		Disabled = 1,
		Password = 2,
		ReadOnly = 4,
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

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, TextBoxStyles styles = TextBoxStyles::None) noexcept;

	};

} //  namespace maxGUI


#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_TEXTBOX_HPP