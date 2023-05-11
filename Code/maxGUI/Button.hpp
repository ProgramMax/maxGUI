// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_BUTTON_HPP
#define MAXGUI_BUTTON_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ButtonImplementation.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <string>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif

#ifndef MAX_CONCEPTS_SUPPORTED
	#include <max/Compiling/Exists.hpp>
#endif

namespace maxGUI
{

#if defined(MAX_CONCEPTS_SUPPORTED)
	template<typename T>
	concept ButtonRequirements = requires(T button_concept) {
		button_concept.OnPressed();
	};
#else
	template<class U, class = decltype(U::OnPressed())>
	struct OnPressedTest{};
#endif


#if defined(MAX_CONCEPTS_SUPPORTED)
	template< ButtonRequirements Behavior >
#else
	template< class Behavior >
#endif
	class Button : public ControlWithText
	{
#ifndef MAX_CONCEPTS_SUPPORTED
		static_assert(max::Compiling::Exists<Behavior, OnPressedTest>::value, "Button behavior must implement an OnPressed() static member function.");
#endif

	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit Button(HWND window_handle) noexcept;
#endif

		~Button() noexcept override;

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, ButtonStyles styles = ButtonStyles::None) noexcept;
#endif

	//protected:

#if defined(MAX_PLATFORM_WINDOWS)
		void OnCommand(WORD notification) noexcept override;
#endif

		Behavior behavior_;
		ButtonImplementation implementation_;

	};

} //  namespace maxGUI

#include <maxGUI/Button.inl>

#endif // #ifndef MAXGUI_BUTTON_HPP