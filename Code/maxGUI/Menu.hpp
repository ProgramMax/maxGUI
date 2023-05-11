// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_MENU_HPP
#define MAXGUI_MENU_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <string>
#include <vector>

namespace maxGUI
{
	class Menu
	{
	public:

		explicit Menu(std::string text) noexcept;
		Menu(std::string text, std::vector<Menu> submenus) noexcept;

	//private:

		std::string text_;
		std::vector<Menu> submenus_;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_MENU_HPP