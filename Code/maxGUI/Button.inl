// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


namespace {

	template< class Test >
	struct Exists2 {
		template<class U>
		static std::true_type Check(U*);

		template<class U>
		static std::false_type Check(...);

		static constexpr bool value = decltype(Check<Test>(0))::value;
	};

	//template< template< class Behavior > class A = decltype(Behavior::OnPressed())>
	//struct OnPressedTest{};

} // anonymous namespace

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
#if defined(MAX_CONCEPTS_SUPPORTED)
	template< ButtonRequirements Behavior >
#else
	template< class Behavior >
#endif
	Button< Behavior >::Button(HWND window_handle) noexcept
		: ControlWithText(std::move(window_handle))
		, behavior_()
	{}
#endif

#if defined(MAX_PLATFORM_WINDOWS)
#if defined(MAX_CONCEPTS_SUPPORTED)
	template< ButtonRequirements Behavior >
#else
	template< class Behavior >
#endif
	void Button< Behavior >::OnCommand(WORD notification) noexcept {
		//if constexpr (Exists<Behavior, OnPressedTest>::value) {
		//if constexpr (Exists2<Behavior::OnPressed()>::value) {
			if (notification == BN_CLICKED) {
				behavior_.OnPressed();
			}
		//}
	}
#endif

} //  namespace maxGUI