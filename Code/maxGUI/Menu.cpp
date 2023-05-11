// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Menu.hpp>

#include <utility>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{

	Menu::Menu(std::string text) noexcept
		: text_(std::move(text))
		, submenus_()
	{}

	Menu::Menu(std::string text, std::vector<Menu> submenus) noexcept
		: text_(std::move(text))
		, submenus_(std::move(submenus))
	{}

} //  namespace maxGUI