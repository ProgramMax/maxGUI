// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <utility>

#if defined(MAX_PLATFORM_WINDOWS)

namespace maxGUI
{
	
	template< class Behavior >
	DropDownBox< Behavior >::DropDownBox(HWND window_handle) noexcept
		: ControlWithList(window_handle)
		, behavior_()
		, implementation_(window_handle)
	{}

	template< class Behavior >
	DropDownBox< Behavior >::~DropDownBox() noexcept = default;

	template< class Behavior >
	void DropDownBox< Behavior >::OnCommand(WORD notification) noexcept {
		if constexpr (HasOnGainedFocus< Behavior >::value) {
			if (notification == CBN_SETFOCUS ) {
				behavior_.OnGainedFocus(&implementation_);
			}
		}

		if constexpr (HasOnLostFocus< Behavior >::value) {
			if (notification == CBN_KILLFOCUS ) {
				behavior_.OnLostFocus(&implementation_);
			}
		}

		if (notification == CBN_SELCHANGE)
		{
			int index = static_cast<int>(SendMessage(window_handle_, CB_GETCURSEL, 0, 0));
			OnSelectionChanged(index);
		}
	}

	template< class Behavior >
	HWND DropDownBox< Behavior >::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::vector<std::string> list, DropDownBoxStyles styles) noexcept {
		return DropDownBoxImplementation::Create(std::move(parent_window_handle), std::move(rectangle), std::move(list), std::move(styles));
	};

} //  namespace maxGUI

#endif