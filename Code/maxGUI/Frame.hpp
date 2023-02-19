// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FRAME_HPP
#define MAXGUI_FRAME_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <maxGUI/ControlWithText.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	class Frame : public ControlWithText
	{
	public:

		explicit Frame(HWND window_handle) noexcept;

		~Frame() noexcept override = default;

		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text) noexcept;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_FRAME_HPP