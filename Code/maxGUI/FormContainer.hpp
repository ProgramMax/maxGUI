// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORMCONTAINER_HPP
#define MAXGUI_FORMCONTAINER_HPP

#include <memory>
#include <string>
#include <vector>

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif
	#include <Windows.h>
#elif defined(MAX_PLATFORM_LINUX)
	#include <QApplication>
#endif

#include <maxGUI/FormConcept.hpp>
#include <maxGUI/FormStyles.hpp>
#include <maxGUI/FormAllocatorConcept.hpp>

namespace maxGUI
{

	class FormContainer {
	public:

		#if defined(MAX_PLATFORM_WINDOWS)
				explicit FormContainer(HINSTANCE instance_handle) noexcept;
		#elif defined(MAX_PLATFORM_LINUX)
				explicit FormContainer(QApplication* app) noexcept;
		#endif

		template <typename FormType>
		bool CreateForm(int width, int height, std::string title, FormAllocatorConcept* form_allocator, FormStyles styles = FormStyles::None) noexcept;

		std::vector<std::unique_ptr<FormConcept>> forms_;

		#if defined(MAX_PLATFORM_WINDOWS)
			HINSTANCE instance_handle_;
		#elif defined(MAX_PLATFORM_LINUX)
			QApplication* app_;
		#endif

	//private:

#if defined(MAX_PLATFORM_WINDOWS)
			struct CreationParameters {
				CreationParameters(FormAllocatorConcept* form_allocator, FormContainer* form_container) noexcept
					: form_allocator_(std::move(form_allocator))
					, form_container_(std::move(form_container))
				{}

				FormAllocatorConcept* form_allocator_;
				FormContainer* form_container_;
			};

			static LPCTSTR maxgui_window_class_name;
			static LPCTSTR maxgui_creation_parameters_property_name;
			static LPCTSTR maxgui_formconcept_property_name;

			static LRESULT CALLBACK BaseWindowProcedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam) noexcept;
#endif

	};

} // namespace maxGUI

#include <maxGUI/FormContainer.inl>

#endif // #ifndef MAXGUI_FORMCONTAINER_HPP