// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_CONTROL_HPP
#define MAXGUI_CONTROL_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <memory>
#include <type_traits>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#elif defined(MAX_PLATFORM_LINUX)
	#include <QWidget>
#endif

namespace {

	// TODO: Use max's Exists here
	template< typename T >
	struct HasOnGainedFocus {
		typedef char yes[1];
		typedef char no[2];

		// If you want only non-static member functions:
		//template <typename U> static yes& test(typename std::enable_if<std::is_member_function_pointer_v<decltype(&U::OnGainedFocus)>, bool>::type = 0);
		// If you want static and non-static member functions:
		template <typename U> static yes& test(typename std::enable_if<std::is_function_v<decltype(U::OnGainedFocus)>, bool>::type = 0);
		template <typename U> static no& test(...);
		static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(yes&);
	};

	template< typename T >
	struct HasOnLostFocus {
		typedef char yes[1];
		typedef char no[2];

		// If you want only non-static member functions:
		//template <typename U> static yes& test(typename std::enable_if<std::is_member_function_pointer_v<decltype(&U::OnLostFocus)>, bool>::type = 0);
		// If you want static and non-static member functions:
		template <typename U> static yes& test(typename std::enable_if<std::is_function_v<decltype(U::OnLostFocus)>, bool>::type = 0);
		template <typename U> static no& test(...);
		static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(yes&);
	};

} // anonymous namespace

namespace maxGUI
{

	class Control {
	public:


#if defined(MAX_PLATFORM_WINDOWS)
		explicit Control(HWND window_handle) noexcept;
#endif

		// TODO: Do we really need this to be virtual?
		virtual ~Control() noexcept = default;

		void Move(max::Containers::Rectangle<int, int> rectangle) noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
		HWND window_handle_;
#endif

	//protected:

#if defined(MAX_PLATFORM_WINDOWS)
		void NewSystemFont() noexcept;

		virtual void OnCommand(WORD notification) noexcept;
#endif

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_CONTROL_HPP
