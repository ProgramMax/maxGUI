// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORMCONCEPT_HPP
#define MAXGUI_FORMCONCEPT_HPP

#include <memory>
#include <vector>

#include <max/Compiling/Configuration.hpp>
#include <maxGUI/Control.hpp>
#include <maxGUI/Menu.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>

	#include <maxGUI/Win32String.hpp>
#elif defined(MAX_PLATFORM_LINUX)
	#include <string>

	#include <QWidget>

	#include <maxGUI/FormStyles.hpp>
#endif

namespace {

	// TODO: Use max's Exists here
	template< typename T >
	struct HasOnPressed {
		typedef char yes[1];
		typedef char no[2];

		template <typename U> static yes& test(typename std::enable_if<std::is_function_v<decltype(U::OnPressed)>, bool>::type = 0);
		template <typename U> static no& test(...);
		static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(yes&);
	};

} // anonymous namespace

namespace maxGUI
{

	class FormConcept {
	public:

		#if defined(MAX_PLATFORM_WINDOWS)
			explicit FormConcept(HWND window_handle) noexcept;
		#elif defined(MAX_PLATFORM_LINUX)
			FormConcept(int width, int height, std::string title, FormStyles styles) noexcept;
		#endif
		virtual ~FormConcept() noexcept;

		virtual void OnResized(FormConcept* form, int width, int height) noexcept = 0;
		virtual void OnClosed(FormConcept* form) noexcept = 0;
		virtual void OnCreated(FormConcept* form) noexcept = 0;
		#if defined(MAX_PLATFORM_WINDOWS)
			virtual LRESULT OnWindowMessage(FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept = 0;
		#endif

			template< typename T, typename... Params >
			T* AppendMenu(Params&&... params) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
				bool is_first_menu = menus_.size() == 0;
				if (is_first_menu) {
					menu_bar_handle_ = CreateMenu();

					MENUINFO menu_info = { 0 };
					menu_info.cbSize = sizeof(menu_info);
					menu_info.fMask = MIM_STYLE;
					menu_info.dwStyle = MNS_NOTIFYBYPOS;
					SetMenuInfo(menu_bar_handle_, &menu_info);

					::SetMenu(window_handle_, menu_bar_handle_);
				}

				HMENU menu_handle = T::Create(menu_bar_handle_, std::forward<Params>(params)...);
				auto menu_ptr = std::make_unique<T>(std::move(menu_handle));
				T* raw_menu_ptr = menu_ptr.get();
				menus_.push_back(std::move(menu_ptr));


				if (is_first_menu) {
					// TODO: This is only required if the window has already been drawn. IE the menus were added after WM_CREATE
					DrawMenuBar(window_handle_);
				}

				return raw_menu_ptr;
#else
				// TODO: Implement on other platforms
				return nullptr;
#endif
			}

		template<typename T, typename... Params>
		T* AddControl(Params&&... params) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
			HWND window_handle = T::Create(window_handle_, std::forward<Params>(params)...);
			auto control_ptr = std::make_unique<T>(std::move(window_handle));
#elif defined(MAX_PLATFORM_LINUX)
			auto* widget = T::Create(&window_, std::forward<Params>(params)...);
			auto control_ptr = std::make_unique<T>(std::move(widget));
#endif
			control_ptr->NewSystemFont();
			T* raw_control_ptr = control_ptr.get();
			controls_.push_back(std::move(control_ptr));
#if defined(MAX_PLATFORM_LINUX)
			// TODO: We should only show after all controls are added.
			window_.show();
#endif
			return raw_control_ptr;
		}

		#if defined(MAX_PLATFORM_WINDOWS)
			HWND window_handle_;
			HMENU menu_bar_handle_;
		#elif defined(MAX_PLATFORM_LINUX)
			QWidget window_;
		#endif

		std::vector<std::unique_ptr<Control>> controls_;
#if defined(MAX_PLATFORM_WINDOWS)
		std::vector<std::unique_ptr<Menu>> menus_;
#endif

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_FORMCONCEPT_HPP