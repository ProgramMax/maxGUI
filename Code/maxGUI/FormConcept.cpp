// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/FormConcept.hpp>

#include <utility>


namespace maxGUI {

	#if defined(MAX_PLATFORM_WINDOWS)
		FormConcept::FormConcept(HWND window_handle) noexcept
			: window_handle_(std::move(window_handle))
		{}
	#elif defined(MAX_PLATFORM_LINUX)
		FormConcept::FormConcept(int width, int height, std::string title, FormStyles styles) noexcept
			: window_()
		{
			window_.setFixedSize(width, height);

			// TODO: Set the title & styles
			(void)title;
			(void)styles;

			// TODO: Ideally, once all controls are added the form will be shown.
			//window_.show();
		}
	#endif

	FormConcept::~FormConcept() noexcept = default;

} // namespace maxGUI