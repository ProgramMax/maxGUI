// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <utility>

#if defined(MAX_PLATFORM_WINDOWS)
	#include <maxGUI/Win32String.hpp>
#endif

namespace maxGUI
{
	
#if defined(MAX_PLATFORM_WINDOWS)
	template< class Behavior >
	MultilineTextBox< Behavior >::MultilineTextBox(HWND window_handle) noexcept
		: ControlWithText(window_handle)
		, behavior_()
		, implementation_(window_handle)
	{}
#elif defined(MAX_PLATFORM_LINUX)
	template< class Behavior >
	MultilineTextBox< Behavior >::MultilineTextBox(QTextEdit* widget) noexcept
		: ControlWithText()
		, behavior_()
		, implementation_()
	{
		(void)widget;
	}
#endif

	template< class Behavior >
	MultilineTextBox< Behavior >::~MultilineTextBox() noexcept = default;

#if defined(MAX_PLATFORM_WINDOWS)
	template< class Behavior >
	HWND MultilineTextBox< Behavior >::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, MultilineTextBoxStyles styles) noexcept {
		return MultilineTextBoxImplementation::Create(std::move(parent_window_handle), std::move(rectangle), std::move(text), std::move(styles));
	}
#elif defined(MAX_PLATFORM_LINUX)
	template< class Behavior >
	QTextEdit* MultilineTextBox< Behavior >::Create(QWidget* parent_window, max::Containers::Rectangle<int, int> rectangle, std::string text, MultilineTextBoxStyles styles) noexcept {
		return MultilineTextBoxImplementation::Create(std::move(parent_window), std::move(rectangle), std::move(text), std::move(styles));
	}
#endif

#if defined(MAX_PLATFORM_WINDOWS)
	template< class Behavior >
	void MultilineTextBox< Behavior >::OnCommand(WORD notification) noexcept {
		if constexpr (HasOnGainedFocus< Behavior >::value) {
			if (notification == EN_SETFOCUS ) {
				behavior_.OnGainedFocus(&implementation_);
			}
		}

		if constexpr (HasOnLostFocus< Behavior >::value) {
			if (notification == EN_KILLFOCUS ) {
				behavior_.OnLostFocus(&implementation_);
			}
		}
	}
#endif

} //  namespace maxGUI
