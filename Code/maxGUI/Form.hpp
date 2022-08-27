// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORM_HPP
#define MAXGUI_FORM_HPP

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/Control.hpp>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

namespace maxGUI
{

	enum class FormStyles {
		None = 0,
		DialogBox = 1,
		FixedSize = 2,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::FormStyles);

namespace maxGUI
{

	class FormConcept {
	public:

		explicit FormConcept(HWND window_handle) noexcept;
		virtual ~FormConcept() noexcept = default;

		virtual void OnResized(FormConcept* form, int height, int width) noexcept = 0;
		virtual void OnClosed(FormConcept* form) noexcept = 0;
		virtual void OnCreated(FormConcept* form) noexcept = 0;
		virtual LRESULT OnWindowMessage(FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept = 0;

		// TODO: Can this be templated so the factories don't need to be templated?
		Control* AddControl(const ControlFactory* control_factory) noexcept;

		HWND window_handle_;
		std::vector<std::unique_ptr<Control>> controls_;

	};

	template<typename T>
	class FormModel : public FormConcept {
	public:

		FormModel(std::unique_ptr<T> form, HWND window_handle) noexcept;
		~FormModel() noexcept override = default;

		void OnResized(FormConcept* form, int height, int width) noexcept override;
		void OnClosed(FormConcept* form) noexcept override;
		void OnCreated(FormConcept* form) noexcept override;
		LRESULT OnWindowMessage(FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept override;

	private:

		std::unique_ptr<T> form_;

	};

	class FormAllocatorConcept {
	public:
	
		virtual ~FormAllocatorConcept() noexcept = default;

		virtual std::unique_ptr<FormConcept> AllocateForm(HWND window_handle) noexcept = 0;

	};

	template<typename T>
	class FormAllocatorModel : public FormAllocatorConcept {
	public:

		virtual ~FormAllocatorModel() noexcept override = default;
		std::unique_ptr<FormConcept> AllocateForm(HWND window_handle) noexcept override;

	};

	template<typename T>
	std::unique_ptr<FormAllocatorConcept> GetDefaultFormAllocator() noexcept;

	class FormContainer {
	public:

		explicit FormContainer(HINSTANCE instance_handle) noexcept;

		template <typename FormFactoryType>
		bool CreateForm(FormFactoryType& form_factory, int height, int width, std::string title) noexcept;

		template <typename FormFactoryType>
		bool CreateForm(FormFactoryType& form_factory, int height, int width, std::string title, FormStyles styles) noexcept;

		std::vector<std::unique_ptr<FormConcept>> forms_;
		HINSTANCE instance_handle_;

	};

	class FormFactory {
	public:

		explicit FormFactory(std::unique_ptr<FormAllocatorConcept> form_allocator) noexcept;
		// Explicitly delete these to silence /Wall on MSVC
		FormFactory(const FormFactory& rhs) = delete;
		FormFactory& operator =(const FormFactory& rhs) = delete;

		bool CreateForm(HINSTANCE instance_handle, int height, int width, std::string title, FormStyles styles) noexcept;

		// This is set by FormContainer::CreateForm() and needs to remain set until WM_CREATE is received
		FormContainer* form_container_ = nullptr;
		std::unique_ptr<FormAllocatorConcept> form_allocator_;

	};

} // namespace maxGUI

#include <maxGUI/Form.inl>

#endif // #ifndef MAXGUI_FORM_HPP