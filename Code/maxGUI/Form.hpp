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

	class Form {
	public:

		explicit Form(HWND window_handle) noexcept;

		virtual ~Form() noexcept = default;

		virtual void OnCreated() noexcept;
		virtual void OnResized(int new_height, int new_width) noexcept;
		virtual void OnClosed() noexcept;

		
		virtual LRESULT OnWindowMessage(UINT message, WPARAM wparam, LPARAM lparam) noexcept;

		// TODO: Can this be templated so the factories don't need to be templated?
		Control* AddControl(const ControlFactory* control_factory) noexcept;

		HWND window_handle_;
		std::vector<std::unique_ptr<Control>> controls_;

	};

	class FormContainer {
	public:

		explicit FormContainer(HINSTANCE instance_handle) noexcept;

		template <typename FormFactoryType>
		bool CreateForm(FormFactoryType& form_factory, int height, int width, std::string title) noexcept {
			return CreateForm(form_factory, std::move(height), std::move(width), std::move(title), FormStyles::None);
		}

		template <typename FormFactoryType>
		bool CreateForm(FormFactoryType& form_factory, int height, int width, std::string title, FormStyles styles) noexcept {
			form_factory.form_container_ = this;
			return form_factory.CreateForm(instance_handle_, std::move(height), std::move(width), std::move(title), std::move(styles));
		}

		std::vector<std::unique_ptr<Form>> forms_;
		HINSTANCE instance_handle_;

	};

	class FormFactoryImplementationDetails {
	public:

		bool CreateForm(HINSTANCE instance_handle, int height, int width, std::string title, FormStyles styles) noexcept;

		virtual std::unique_ptr<Form> AllocateForm(HWND window_handle) noexcept = 0;

		// This is set by FormContainer::CreateForm() and needs to remain set until WM_CREATE is received
		FormContainer* form_container_ = nullptr;

	};

	template <typename FormType>
	class FormFactory : public FormFactoryImplementationDetails {
	public:

		virtual ~FormFactory() noexcept = default;

		std::unique_ptr<Form> AllocateForm(HWND window_handle) noexcept override {
			// TODO: Use allocator
			return std::make_unique<FormType>(window_handle);
		}

		// TODO: Add allocator

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_FORM_HPP