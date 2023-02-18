// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_BUTTON_HPP
#define MAXGUI_BUTTON_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#ifndef MAX_CONCEPTS_SUPPORTED
	#include <max/Compiling/Exists.hpp>
#endif

namespace maxGUI
{

	enum class ButtonStyles : uint8_t {
		None = 0,
		Disabled = 1,
		Default = 2,
		Flat = 4,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::ButtonStyles);

namespace maxGUI
{

	class ButtonConcept
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit ButtonConcept(HWND window_handle) noexcept;
#endif
		virtual ~ButtonConcept() noexcept;

		virtual void OnPressed(ButtonConcept* button) noexcept = 0;

	};

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

		~Button() noexcept override = default;

	//protected:

#if defined(MAX_PLATFORM_WINDOWS)
		void OnCommand(WORD notification) noexcept override;
#endif

		Behavior behavior_;

	};
	
	class ButtonFactoryImplementationDetails
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND CreateButton(std::string text, Rectangle rectangle, ButtonStyles styles, HWND parent_window_handle) noexcept;
#endif

	};

	template <typename ButtonType>
	class ButtonFactory : public ControlWithTextFactory
	{
	public:

		ButtonFactory(Rectangle rectangle, std::string text) noexcept
			: ButtonFactory(std::move(rectangle), std::move(text), ButtonStyles::None)
		{}

		ButtonFactory(Rectangle rectangle, std::string text, ButtonStyles styles) noexcept
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
			, styles_(std::move(styles))
		{}

		~ButtonFactory() noexcept override = default;

#if defined(MAX_PLATFORM_WINDOWS)
		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = ButtonFactoryImplementationDetails::CreateButton(text_, rectangle_, styles_, std::move(parent_window_handle));
			return std::make_unique<ButtonType>(std::move(window_handle));
		}
#endif

		ButtonStyles styles_;

	};


} //  namespace maxGUI

#include <maxGUI/Button.inl>

#endif // #ifndef MAXGUI_BUTTON_HPP