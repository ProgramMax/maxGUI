// Copyright 2024, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <utility>

#if defined(MAX_PLATFORM_WINDOWS)

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{

	template<typename T, typename... Params>
	T* ParentMenu::AppendMenu(Params&&... params) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		HMENU menu_handle = T::Create(menu_handle_, next_submenu_id_, std::forward<Params>(params)...);
		auto menu_ptr = std::make_unique<T>(menu_handle);

		next_submenu_id_++;

		T* raw_menu_ptr = menu_ptr.get();
		submenus_.push_back(std::move(menu_ptr));
#endif
		return raw_menu_ptr;
	}

	template< class Behavior >
	PressableMenu< Behavior >::PressableMenu(HMENU menu_handle) noexcept
		: Menu(std::move(menu_handle))
	{}

	template< class Behavior >
	HMENU PressableMenu< Behavior >::Create(HMENU parent_menu, ULONG_PTR id, std::string text) noexcept {
		HMENU submenu_handle = CreatePopupMenu();
		
		auto win32_text = Utf8ToWin32String(std::move(text));
		BOOL result = ::AppendMenu(parent_menu, MF_STRING, reinterpret_cast<UINT_PTR>(submenu_handle), win32_text.text_);
		if (result == 0) {
			// error
		}

		MENUITEMINFO menu_item_info = { 0 };
		menu_item_info.cbSize = sizeof(menu_item_info);
		//menu_item_info.fMask = MIIM_DATA | MIIM_STRING | MIIM_ID;// | MIIM_TYPE;
		//menu_item_info.fMask = MIIM_DATA | MIIM_TYPE | MIIM_ID;
		menu_item_info.fMask = MIIM_DATA | MIIM_TYPE;// | MIIM_ID;
		menu_item_info.fType = MFT_STRING;
		menu_item_info.dwTypeData = win32_text.text_;
		menu_item_info.cch = win32_text.char_count_;
		menu_item_info.dwItemData = reinterpret_cast<ULONG_PTR>(&Behavior::OnPressed);

		result = SetMenuItemInfo(parent_menu, id, TRUE, &menu_item_info);
		if (result == 0) {
			// error
		}

		return submenu_handle;
	}

} //  namespace maxGUI

#endif