// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_RADIOBUTTON_HPP
#define MAXGUI_RADIOBUTTON_HPP


#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	enum class RadioButtonStyles : uint8_t {
		None = 0,
		Disabled = 1,
		FirstInGroup = 2,
		Flat = 4,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::RadioButtonStyles);

namespace maxGUI
{

	class RadioButton : public ControlWithText
	{
	public:

		explicit RadioButton(HWND window_handle) noexcept;

		~RadioButton() noexcept override = default;

		static HWND Create(HWND parent_window_handle, Rectangle rectangle, std::string text, RadioButtonStyles styles = RadioButtonStyles::None) noexcept;

		virtual void OnPressed() noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_RADIOBUTTON_HPP