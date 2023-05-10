// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CHECKBOXIMPLEMENTATION_HPP
#define MAXGUI_CHECKBOXIMPLEMENTATION_HPP

#include <string>

#include <max/Compiling/Bitmask.hpp>
#include <max/Containers/Rectangle.hpp>
#include <max/Compiling/Configuration.hpp>
#include <maxGUI/ControlWithTextImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif

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

	class CheckBoxImplementation : public ControlWithTextImplementation
	{
	public:

		explicit CheckBoxImplementation(HWND window_handle) noexcept;

		~CheckBoxImplementation() noexcept;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, CheckBoxStyles styles) noexcept;

		bool IsChecked() const noexcept;
		void Check() noexcept;
		void Uncheck() noexcept;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_CHECKBOXIMPLEMENTATION_HPP