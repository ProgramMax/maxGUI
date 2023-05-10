// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <utility>

#if defined(MAX_PLATFORM_WINDOWS)
	#include <maxGUI/Win32String.hpp>
#endif

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
#if defined(MAX_CONCEPTS_SUPPORTED)
	template< ButtonRequirements Behavior >
#else
	template< class Behavior >
#endif
	Button< Behavior >::Button(HWND window_handle) noexcept
		: ControlWithText(window_handle)
		, behavior_()
		, implementation_(window_handle)
	{}
#endif

#if defined(MAX_PLATFORM_WINDOWS)
#if defined(MAX_CONCEPTS_SUPPORTED)
	template< ButtonRequirements Behavior >
#else
	template< class Behavior >
#endif
	Button< Behavior >::~Button() noexcept = default;
#endif

#if defined(MAX_PLATFORM_WINDOWS)
#if defined(MAX_CONCEPTS_SUPPORTED)
	template< ButtonRequirements Behavior >
#else
	template< class Behavior >
#endif
	HWND Button< Behavior >::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, ButtonStyles styles) noexcept {
		return ButtonImplementation::Create(std::move(parent_window_handle), std::move(rectangle), std::move(text), std::move(styles));
	}
#endif

#if defined(MAX_PLATFORM_WINDOWS)
#if defined(MAX_CONCEPTS_SUPPORTED)
	template< ButtonRequirements Behavior >
#else
	template< class Behavior >
#endif
	void Button< Behavior >::OnCommand(WORD notification) noexcept {
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
			behavior_.OnPressed();
		}
	}
#endif

} //  namespace maxGUI