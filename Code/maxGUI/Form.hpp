// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORM_HPP
#define MAXGUI_FORM_HPP

#include <max/Compiling/ThrowSpecification.hpp>
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

	class Form {
	public:

		explicit Form(HWND window_handle) MAX_DOES_NOT_THROW;

		virtual ~Form() MAX_DOES_NOT_THROW = default;

		virtual void OnCreated() MAX_DOES_NOT_THROW;
		virtual void OnResized(int new_height, int new_width) MAX_DOES_NOT_THROW;
		virtual void OnClosed() MAX_DOES_NOT_THROW;

		Control* AddControl(const ControlFactory* control_factory) MAX_DOES_NOT_THROW;

		HWND window_handle_;
		std::vector<std::unique_ptr<Control>> controls_;

	};

	class FormContainer {
	public:

		explicit FormContainer(HINSTANCE instance_handle) MAX_DOES_NOT_THROW;

		template <typename FormFactoryType>
		bool CreateForm(FormFactoryType& form_factory, int height, int width, std::string title) MAX_DOES_NOT_THROW {
			form_factory.form_container_ = this;
			return form_factory.CreateForm(instance_handle_, std::move(height), std::move(width), std::move(title));
		}

		std::vector<std::unique_ptr<Form>> forms_;
		HINSTANCE instance_handle_;

	};

	class FormFactoryImplementationDetails {
	public:

		bool CreateForm(HINSTANCE instance_handle, int height, int width, std::string title) MAX_DOES_NOT_THROW;

		virtual std::unique_ptr<Form> AllocateForm(HWND window_handle) MAX_DOES_NOT_THROW = 0;

		// This is set by FormContainer::CreateForm() and needs to remain set until WM_CREATE is received
		FormContainer* form_container_ = nullptr;

	};

	template <typename FormType>
	class FormFactory : public FormFactoryImplementationDetails {
	public:

		virtual ~FormFactory() MAX_DOES_NOT_THROW = default;

		std::unique_ptr<Form> AllocateForm(HWND window_handle) MAX_DOES_NOT_THROW override {
			// TODO: Use allocator
			return std::make_unique<FormType>(window_handle);
		}

		// TODO: Add allocator

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_FORM_HPP