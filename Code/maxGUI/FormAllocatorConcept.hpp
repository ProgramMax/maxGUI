// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORMALLOCATORCONCEPT_HPP
#define MAXGUI_FORMALLOCATORCONCEPT_HPP

#include <memory>

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif
	#include <Windows.h>
#elif defined(MAX_PLATFORM_LINUX)
	#include <string>

	#include <maxGUI/FormStyles.hpp>
#endif

#include <maxGUI/FormConcept.hpp>

namespace maxGUI
{

	class FormAllocatorConcept {
	public:

		virtual ~FormAllocatorConcept() noexcept;

		#if defined(MAX_PLATFORM_WINDOWS)
			virtual std::unique_ptr<FormConcept> AllocateForm(HWND window_handle) noexcept = 0;
		#elif defined(MAX_PLATFORM_LINUX)
			virtual std::unique_ptr<FormConcept> AllocateForm(int height, int width, std::string title, FormStyles styles) noexcept = 0;
		#endif

		};

} // namespace maxGUI

#endif // #ifndef MAXGUI_FORMALLOCATORCONCEPT_HPP