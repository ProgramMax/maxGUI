// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORMFACTORY_HPP
#define MAXGUI_FORMFACTORY_HPP

#include <memory>
#include <string>

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif
	#include <Windows.h>
#elif defined(MAX_PLATFORM_LINUX)
	#include <QApplication>
#endif

#include <maxGUI/FormAllocatorConcept.hpp>
#include <maxGUI/FormContainer.hpp>
#include <maxGUI/FormStyles.hpp>

namespace maxGUI
{

	class FormFactory {
	public:

		explicit FormFactory(std::unique_ptr<FormAllocatorConcept> form_allocator) noexcept;
		// Explicitly delete these to silence /Wall on MSVC
		FormFactory(const FormFactory& rhs) = delete;
		FormFactory& operator =(const FormFactory& rhs) = delete;

		#if defined(MAX_PLATFORM_WINDOWS)
			bool CreateForm(HINSTANCE instance_handle, int height, int width, std::string title, FormStyles styles) noexcept;
		#elif defined(MAX_PLATFORM_LINUX)
			bool CreateForm(int height, int width, std::string title, FormStyles style) noexcept;
		#endif

		// On Windows, this is set by FormContainer::CreateForm() and needs to remain set until WM_CREATE is received
		FormContainer* form_container_ = nullptr;
		std::unique_ptr<FormAllocatorConcept> form_allocator_;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_FORMFACTORY_HPP