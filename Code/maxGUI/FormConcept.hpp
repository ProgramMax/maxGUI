// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORMCONCEPT_HPP
#define MAXGUI_FORMCONCEPT_HPP

#include <memory>
#include <vector>

#include <max/Compiling/Configuration.hpp>
#include <maxGUI/Control.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif
	#include <Windows.h>
#elif defined(MAX_PLATFORM_LINUX)
	#include <string>

	#include <QWidget>

	#include <maxGUI/FormStyles.hpp>
#endif

namespace maxGUI
{

	class FormConcept {
	public:

		#if defined(MAX_PLATFORM_WINDOWS)
			explicit FormConcept(HWND window_handle) noexcept;
		#elif defined(MAX_PLATFORM_LINUX)
			FormConcept(int height, int width, std::string title, FormStyles styles) noexcept;
		#endif
		virtual ~FormConcept() noexcept;

		virtual void OnResized(FormConcept* form, int height, int width) noexcept = 0;
		virtual void OnClosed(FormConcept* form) noexcept = 0;
		virtual void OnCreated(FormConcept* form) noexcept = 0;
		#if defined(MAX_PLATFORM_WINDOWS)
			virtual LRESULT OnWindowMessage(FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept = 0;
		#endif

		template<typename T, typename... Params>
		T* AddControl(Params&&... params) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
			HWND window_handle = T::Create(window_handle_, std::forward<Params>(params)...);
			auto control_ptr = std::make_unique<T>(std::move(window_handle));
#elif defined(MAX_PLATFORM_LINUX)
			auto* widget = T::Create(&window_, std::forward<Params>(params)...);
			auto control_ptr = std::make_unique<T>(std::move(widget));
#endif
			T* raw_control_ptr = control_ptr.get();
			controls_.push_back(std::move(control_ptr));
#if defined(MAX_PLATFORM_LINUX)
			// TODO: We should only show after all controls are added.
			window_.show();
#endif
			return raw_control_ptr;
		}

		#if defined(MAX_PLATFORM_WINDOWS)
			HWND window_handle_;
		#elif defined(MAX_PLATFORM_LINUX)
			QWidget window_;
		#endif
		std::vector<std::unique_ptr<Control>> controls_;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_FORMCONCEPT_HPP