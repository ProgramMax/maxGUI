// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CHECKBOX_HPP
#define MAXGUI_CHECKBOX_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	enum class CheckBoxStyles : uint8_t {
		None = 0,
		Disabled = 1,
		Flat = 2,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::CheckBoxStyles);

namespace maxGUI
{

	class CheckBox : public ControlWithText
	{
	public:

		explicit CheckBox(HWND window_handle) noexcept;

		~CheckBox() noexcept override = default;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, CheckBoxStyles styles = CheckBoxStyles::None) noexcept;

		virtual void OnPressed() noexcept;

		bool IsChecked() const noexcept;
		void Check() noexcept;
		void Uncheck() noexcept;

	//protected:

		void OnCommand(WORD notification) noexcept override;

	};
	
} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_BUTTON_HPP