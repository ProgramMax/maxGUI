// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

namespace maxGUI
{
	
	template< class Behavior >
	ListBox< Behavior >::ListBox(HWND window_handle) noexcept
		: ControlWithList(window_handle)
		, behavior_()
		, implementation_(window_handle)
	{}

	template< class Behavior >
	ListBox< Behavior >::~ListBox() noexcept = default;

	template< class Behavior >
	HWND ListBox< Behavior >::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::vector<std::string> list, ListBoxStyles styles) noexcept {
		return ListBoxImplementation::Create(std::move(parent_window_handle), std::move(rectangle), std::move(list), std::move(styles));
	}

	template< class Behavior >
	void ListBox< Behavior >::OnCommand(WORD notification) noexcept {
		if constexpr (HasOnGainedFocus< Behavior >::value) {
			if (notification == LBN_SETFOCUS ) {
				behavior_.OnGainedFocus(&implementation_);
			}
		}

		if constexpr (HasOnLostFocus< Behavior >::value) {
			if (notification == LBN_KILLFOCUS ) {
				behavior_.OnLostFocus(&implementation_);
			}
		}

		if (notification == LBN_SELCHANGE)
		{
			int index = static_cast<int>(SendMessage(window_handle_, LB_GETCURSEL, 0, 0));
			OnSelectionChanged(index);
		}
	}

} //  namespace maxGUI