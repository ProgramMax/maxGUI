// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	template< class Behavior >
	Button< Behavior >::Button(HWND window_handle) noexcept
		: ControlWithText(std::move(window_handle))
		, behavior_()
	{}
#endif

#if defined(MAX_PLATFORM_WINDOWS)
	template< class Behavior >
	void Button< Behavior >::OnCommand(WORD notification) noexcept {
		if (notification == BN_CLICKED)
		{
			behavior_.OnPressed();
		}
	}
#endif

} //  namespace maxGUI