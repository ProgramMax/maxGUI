// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_LABEL_HPP
#define MAXGUI_LABEL_HPP

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	class Label : public ControlWithText
	{
	public:

		explicit Label(HWND window_handle) noexcept;

		~Label() noexcept override = default;

		static HWND Create(HWND parent_window_handle, Rectangle rectangle, std::string text) noexcept;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_LABEL_HPP