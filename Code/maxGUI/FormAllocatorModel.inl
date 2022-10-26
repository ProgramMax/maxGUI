// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <utility>

#include <maxGUI/FormModel.hpp>

namespace maxGUI {

	template<typename T>
	FormAllocatorModel<T>::~FormAllocatorModel() noexcept = default;

	#if defined(MAX_PLATFORM_WINDOWS)
		template<typename T>
		std::unique_ptr<FormConcept> FormAllocatorModel<T>::AllocateForm(HWND window_handle) noexcept {
			auto form = std::make_unique<T>();
			return std::make_unique<FormModel<T>>(std::move(form), std::move(window_handle));
		}
	#elif defined(MAX_PLATFORM_LINUX)
		template<typename T>
		std::unique_ptr<FormConcept> FormAllocatorModel<T>::AllocateForm(int height, int width, std::string title, FormStyles styles) noexcept {
			auto form = std::make_unique<T>();
			return std::make_unique<FormModel<T>>(std::move(form), std::move(height), std::move(width), std::move(title), std::move(styles));
		}
	#endif

	template<typename T>
	std::unique_ptr<FormAllocatorConcept> GetDefaultFormAllocator() noexcept {
		return std::make_unique<FormAllocatorModel<T>>();
	}


} // namespace maxGUI
