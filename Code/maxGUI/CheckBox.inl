// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

namespace maxGUI
{
	
#if defined(MAX_PLATFORM_WINDOWS)

	template< class Behavior >
	CheckBox< Behavior >::CheckBox(HWND window_handle) noexcept
		: ControlWithText(window_handle)
		, behavior_()
		, implementation_(window_handle)
	{}

	template< class Behavior >
	CheckBox< Behavior >::~CheckBox() noexcept = default;

	template< class Behavior >
	HWND CheckBox< Behavior >::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, CheckBoxStyles styles) noexcept {
		return CheckBoxImplementation::Create(std::move(parent_window_handle), std::move(rectangle), std::move(text), std::move(styles));
	}

	template< class Behavior >
	void CheckBox< Behavior >::OnPressed() noexcept {
		if (IsChecked()) {
			Uncheck();
		} else {
			Check();
		}
	}

	template< class Behavior >
	void CheckBox< Behavior >::OnCommand(WORD notification) noexcept {
		if constexpr (HasOnGainedFocus< Behavior >::value) {
			if (notification == BN_SETFOCUS) {
				behavior_.OnGainedFocus(&implementation_);
			}
		}

		if constexpr (HasOnLostFocus< Behavior >::value) {
			if (notification == BN_KILLFOCUS) {
				behavior_.OnLostFocus(&implementation_);
			}
		}

		if (notification == BN_CLICKED)
		{
			OnPressed();
		}
	}

	template< class Behavior >
	bool CheckBox< Behavior >::IsChecked() const noexcept {
		return implementation_.IsChecked();
	}

	template< class Behavior >
	void CheckBox< Behavior >::Check() noexcept {
		return implementation_.Check();
	}

	template< class Behavior >
	void CheckBox< Behavior >::Uncheck() noexcept {
		return implementation_.Uncheck();
	}

#endif

} //  namespace maxGUI