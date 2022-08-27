// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Form.hpp>
#include <maxGUI/EntryPoint.hpp>
#include <maxGUI/Win32String.hpp>
#include <utility>

namespace {

	// TODO: These don't work the way I expect.
	// Currently, I'm using 'requires' instead. But that's more modern. And I want to support older compilers, too.
	/*
	template< typename T >
	struct HasOnCreated {
		typedef char yes;
		struct no { char _[2]; };
		template< typename U, void(U::*)() = &U::OnCreated>
		static yes impl(U*);
		static no impl(...);

		enum { value = sizeof( impl( static_cast<T*>(0) ) ) == sizeof(yes) };
	};

	template< typename T >
	struct HasOnResized {
		typedef char yes;
		struct no { char _[2]; };
		template< typename U, void(U::*)() = &U::OnResized>
		static yes impl(U*);
		static no impl(...);

		enum { value = sizeof( impl( static_cast<T*>(0) ) ) == sizeof(yes) };
	};

	template< typename T >
	struct HasOnClosed {
		typedef char yes;
		struct no { char _[2]; };
		template< typename U, void(U::*)() = &U::OnClosed>
		static yes impl(U*);
		static no impl(...);

		enum { value = sizeof( impl( static_cast<T*>(0) ) ) == sizeof(yes) };
	};

	template< typename T >
	struct HasOnWindowMessage {
		typedef char yes;
		struct no { char _[2]; };
		template< typename U, void(U::*)() = &U::OnWindowMessage>
		static yes impl(U*);
		static no impl(...);

		enum { value = sizeof( impl( static_cast<T*>(0) ) ) == sizeof(yes) };
	};
	*/

} // anonymous namespace

namespace maxGUI {

	template<typename T>
	FormModel<T>::FormModel(std::unique_ptr<T> form, HWND window_handle) noexcept
		: FormConcept(std::move(window_handle))
		, form_(std::move(form))
	{}

	template<typename T>
	void FormModel<T>::OnResized(FormConcept* form, int height, int width) noexcept {
		//if (HasOnResized<T>::value) {
		if constexpr (requires { form_->OnResized(std::move(form), std::move(height), std::move(width)); }) {
			form_->OnResized(std::move(form), std::move(height), std::move(width));
		}
	}

	template<typename T>
	void FormModel<T>::OnClosed(FormConcept* form) noexcept {
		//if (HasOnClosed<T>::value) {
		if constexpr (requires { form_->OnClosed(std::move(form)); }) {
			form_->OnClosed(std::move(form));
		}
	}

	template<typename T>
	void FormModel<T>::OnCreated(FormConcept* form) noexcept {
		//if (HasOnCreated<T>::value) {
		if constexpr (requires { form_->OnCreated(std::move(form)); }) {
			form_->OnCreated(std::move(form));
		}
	}

	template<typename T>
	LRESULT FormModel<T>::OnWindowMessage(FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
		//if (HasOnWindowMessage<T>::value) {
		if constexpr (requires { form_->OnWindowMessage(std::move(form), std::move(message), std::move(wparam), std::move(lparam)); }) {
			return form_->OnWindowMessage(std::move(form), std::move(message), std::move(wparam), std::move(lparam));
		} else {
			return DefWindowProc(window_handle_, message, wparam, lparam);
		}
	}

	template <typename FormFactoryType>
	bool FormContainer::CreateForm(FormFactoryType& form_factory, int height, int width, std::string title) noexcept {
		return CreateForm(form_factory, std::move(height), std::move(width), std::move(title), FormStyles::None);
	}

	template <typename FormFactoryType>
	bool FormContainer::CreateForm(FormFactoryType& form_factory, int height, int width, std::string title, FormStyles styles) noexcept {
		form_factory.form_container_ = this;
		return form_factory.CreateForm(instance_handle_, std::move(height), std::move(width), std::move(title), std::move(styles));
	}

	template<typename T>
	std::unique_ptr<FormConcept> FormAllocatorModel<T>::AllocateForm(HWND window_handle) noexcept {
		auto form = std::make_unique<T>();
		return std::make_unique<FormModel<T>>(std::move(form), window_handle);
	}

	template<typename T>
	std::unique_ptr<FormAllocatorConcept> GetDefaultFormAllocator() noexcept {
		return std::make_unique<FormAllocatorModel<T>>();
	}


} // namespace maxGUI