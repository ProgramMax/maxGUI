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
		FormConcept::FormConcept(int height, int width, std::string title, FormStyles styles) noexcept
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

	Control* FormConcept::AddControl(const ControlFactory* control_factory) noexcept {
		#if defined(MAX_PLATFORM_WINDOWS)
			std::unique_ptr<Control> control_ptr = control_factory->CreateControl(window_handle_);
		#elif defined(MAX_PLATFORM_LINUX)
			std::unique_ptr<Control> control_ptr = control_factory->CreateControl(&window_);
		#endif
		Control* raw_control_ptr = control_ptr.get();
		controls_.push_back(std::move(control_ptr));
		#if defined(MAX_PLATFORM_LINUX)
			// TODO: We should only show after all controls are added.
			window_.show();
		#endif
		return raw_control_ptr;
	}

} // namespace maxGUI