// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CONTROLWITHTEXT_HPP
#define MAXGUI_CONTROLWITHTEXT_HPP

#include <maxGUI/Control.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

namespace maxGUI
{

	class ControlWithText : public Control {
	public:

		explicit ControlWithText(HWND window_handle) noexcept;

		~ControlWithText() noexcept override = default;

		std::string GetText() const noexcept;
		void SetText(std::string text) noexcept;

	};

	class ControlWithTextFactory : public ControlFactory {
	public:

		ControlWithTextFactory(Rectangle rectangle, std::string text) noexcept;

		~ControlWithTextFactory() noexcept override = default;

		std::string text_;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_CONTROLWITHTEXT_HPP