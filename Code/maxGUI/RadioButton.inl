// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Win32String.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

namespace maxGUI
{
	
	template< class Behavior >
	RadioButton< Behavior >::RadioButton(HWND window_handle) noexcept
		: ControlWithText(window_handle)
		, behavior_()
		, implementation_(window_handle)
	{}

	template< class Behavior >
	RadioButton< Behavior >::~RadioButton() noexcept = default;

	template< class Behavior >
	HWND RadioButton< Behavior >::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, RadioButtonStyles style) noexcept {
		return RadioButtonImplementation::Create(std::move(parent_window_handle), std::move(rectangle), std::move(text), std::move(style));
	}

	template< class Behavior >
	void RadioButton< Behavior >::OnPressed() noexcept
	{}

	template< class Behavior >
	void RadioButton< Behavior >::OnCommand(WORD notification) noexcept {
		if constexpr (HasOnGainedFocus< Behavior >::value) {
			if (notification == BN_SETFOCUS ) {
				behavior_.OnGainedFocus(&implementation_);
			}
		}

		if constexpr (HasOnLostFocus< Behavior >::value) {
			if (notification == BN_KILLFOCUS ) {
				behavior_.OnLostFocus(&implementation_);
			}
		}

		if (notification == BN_CLICKED) {
			OnPressed();
		}
	}

} //  namespace maxGUI

#endif