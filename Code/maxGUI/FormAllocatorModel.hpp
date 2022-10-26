// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORMALLOCATORMODEL_HPP
#define MAXGUI_FORMALLOCATORMODEL_HPP

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

#include <maxGUI/FormAllocatorConcept.hpp>

namespace maxGUI
{

	template<typename T>
	class FormAllocatorModel : public FormAllocatorConcept {
	public:

		virtual ~FormAllocatorModel() noexcept override;
		#if defined(MAX_PLATFORM_WINDOWS)
			std::unique_ptr<FormConcept> AllocateForm(HWND window_handle) noexcept override;
		#elif defined(MAX_PLATFORM_LINUX)
			std::unique_ptr<FormConcept> AllocateForm(int height, int width, std::string title, FormStyles styles) noexcept override;
		#endif

	};

	template<typename T>
	std::unique_ptr<FormAllocatorConcept> GetDefaultFormAllocator() noexcept;

} // namespace maxGUI

#include <maxGUI/FormAllocatorModel.inl>

#endif // #ifndef MAXGUI_FORMALLOCATORMODEL_HPP
