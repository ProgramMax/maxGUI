// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Win32String.hpp>

#include <utility>

#if defined(MAX_PLATFORM_WINDOWS)

namespace maxGUI
{

	template< class Behavior >
	TextBox< Behavior >::TextBox(HWND window_handle) noexcept
		: ControlWithText(window_handle)
		, behavior_()
		, implementation_(window_handle)
	{}

	template< class Behavior >
	TextBox< Behavior >::~TextBox() noexcept = default;
	
	template< class Behavior >
	HWND TextBox< Behavior >::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, TextBoxStyles styles) noexcept {
		return TextBoxImplementation::Create(std::move(parent_window_handle), std::move(rectangle), std::move(text), std::move(styles));
	}

#if defined(MAX_PLATFORM_WINDOWS)
	template< class Behavior >
	void TextBox< Behavior >::OnCommand(WORD notification) noexcept {
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

#endif