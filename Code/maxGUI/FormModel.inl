// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <type_traits>
#include <utility>

namespace {

	template< typename T >
	struct HasOnCreated {
		typedef char yes[1];
		typedef char no[2];

		template <typename U> static yes& test(typename std::enable_if<std::is_member_function_pointer<decltype(&U::OnCreated)>::value, bool>::type = 0);
		template <typename U> static no& test(...);
		static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(yes&);
	};

	template< typename T >
	struct HasOnResized {
		typedef char yes[1];
		typedef char no[2];

		template <typename U> static yes& test(typename std::enable_if<std::is_member_function_pointer<decltype(&U::OnResized)>::value, bool>::type = 0);
		template <typename U> static no& test(...);
		static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(yes&);
	};

	template< typename T >
	struct HasOnClosed {
		typedef char yes[1];
		typedef char no[2];

		template <typename U> static yes& test(typename std::enable_if<std::is_member_function_pointer<decltype(&U::OnClosed)>::value, bool>::type = 0);
		template <typename U> static no& test(...);
		static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(yes&);
	};

	template< typename T >
	struct HasOnWindowMessage {
		typedef char yes[1];
		typedef char no[2];

		template <typename U> static yes& test(typename std::enable_if<std::is_member_function_pointer<decltype(&U::OnWindowMessage)>::value, bool>::type = 0);
		template <typename U> static no& test(...);
		static bool const value = sizeof(test<typename std::remove_cv<T>::type>(0)) == sizeof(yes&);
	};

} // anonymous namespace


namespace maxGUI {

	#if defined(MAX_PLATFORM_WINDOWS)
		template<typename T>
		FormModel<T>::FormModel(std::unique_ptr<T> form, HWND window_handle) noexcept
			: FormConcept(std::move(window_handle))
			, form_(std::move(form))
		{}
	#elif defined(MAX_PLATFORM_LINUX)
		template<typename T>
		FormModel<T>::FormModel(std::unique_ptr<T> form, int height, int width, std::string title, FormStyles styles) noexcept
			: FormConcept(std::move(height), std::move(width), std::move(title), std::move(styles))
			, form_(std::move(form))
		{}
	#endif

	template<typename T>
	void FormModel<T>::OnResized(FormConcept* form, int height, int width) noexcept {
		if constexpr (HasOnResized<T>::value) {
			form_->OnResized(std::move(form), std::move(height), std::move(width));
		}
	}

	template<typename T>
	void FormModel<T>::OnClosed(FormConcept* form) noexcept {
		if constexpr (HasOnClosed<T>::value) {
			form_->OnClosed(std::move(form));
		}
	}

	template<typename T>
	void FormModel<T>::OnCreated(FormConcept* form) noexcept {
		if constexpr (HasOnCreated<T>::value) {
			form_->OnCreated(std::move(form));
		}
	}

	#if defined(MAX_PLATFORM_WINDOWS)
		template<typename T>
		LRESULT FormModel<T>::OnWindowMessage(FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
			if constexpr (HasOnWindowMessage<T>::value) {
				return form_->OnWindowMessage(std::move(form), std::move(message), std::move(wparam), std::move(lparam));
			} else {
				return DefWindowProc(window_handle_, message, wparam, lparam);
			}
		}
	#endif

} // namespace maxGUI