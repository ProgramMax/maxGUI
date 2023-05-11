// Copyright 2024, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Menu.hpp>

#include <utility>

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	Menu::Menu(HMENU menu_handle) noexcept
		: menu_handle_(std::move(menu_handle))
	{}
#endif

#if defined(MAX_PLATFORM_WINDOWS)
	ParentMenu::ParentMenu(HMENU menu_handle) noexcept
		: Menu(std::move(menu_handle))
		, next_submenu_id_(0)
	{}
#endif

#if defined(MAX_PLATFORM_WINDOWS)
	HMENU ParentMenu::Create(HMENU parent_menu, std::string text) noexcept {
		HMENU menu_handle = CreateMenu();

		auto win32_text = Utf8ToWin32String(std::move(text));
		BOOL result = ::AppendMenu(parent_menu, MF_POPUP | MF_STRING, reinterpret_cast<UINT_PTR>(menu_handle), win32_text.text_);
		if (result == 0) {
			// error
		}

		return menu_handle;
	}
#endif

}