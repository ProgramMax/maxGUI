// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_TEXTBOXIMPLEMENTATION_HPP
#define MAXGUI_TEXTBOXIMPLEMENTATION_HPP

#include <string>

#include <max/Compiling/Bitmask.hpp>
#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithTextImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif


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

	class TextBoxImplementation : public ControlWithTextImplementation
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit TextBoxImplementation(HWND window_handle) noexcept;
#endif

		~TextBoxImplementation() noexcept override;

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, TextBoxStyles styles) noexcept;
#endif

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_TEXTBOXIMPLEMENTATION_HPP