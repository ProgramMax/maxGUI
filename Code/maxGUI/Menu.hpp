// Copyright 2024, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_MENU_HPP
#define MAXGUI_MENU_HPP


#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <memory>
#include <string>
#include <vector>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif


namespace maxGUI
{

	class Menu {
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit Menu(HMENU menu_handle) noexcept;
#endif

		virtual ~Menu() noexcept = default;

	protected:

#if defined(MAX_PLATFORM_WINDOWS)
		HMENU menu_handle_;
#endif

	};

	class ParentMenu : public Menu
	{
	public:

		explicit ParentMenu(HMENU menu_handle) noexcept;

		~ParentMenu() noexcept override = default;

#if defined(MAX_PLATFORM_WINDOWS)
		static HMENU Create(HMENU parent_menu, std::string text) noexcept;
#endif

		template<typename T, typename... Params>
		T* AppendMenu(Params&&... params) noexcept;

		std::vector<std::unique_ptr<Menu>> submenus_;

		ULONG_PTR next_submenu_id_;

	};

	class DefaultMenuBehavior {
	};

	template< class Behavior = DefaultMenuBehavior >
	class PressableMenu : public Menu
	{
	public:

		explicit PressableMenu(HMENU menu_handle) noexcept;

		~PressableMenu() noexcept override = default;

		static HMENU Create(HMENU parent_menu, ULONG_PTR id, std::string text) noexcept;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#include <maxGUI/Menu.inl>

#endif // #ifndef MAXGUI_MENU_HPP