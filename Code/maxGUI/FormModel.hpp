// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORMMODEL_HPP
#define MAXGUI_FORMMODEL_HPP

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

	template<typename T>
	class FormModel : public FormConcept {
	public:

		#if defined(MAX_PLATFORM_WINDOWS)
			FormModel(std::unique_ptr<T> form, HWND window_handle) noexcept;
		#elif defined(MAX_PLATFORM_LINUX)
			FormModel(std::unique_ptr<T> form, int width, int height, std::string title, FormStyles styles) noexcept;
		#endif
		~FormModel() noexcept override = default;

		void OnResized(FormConcept* form, int width, int height) noexcept override;
		void OnClosed(FormConcept* form) noexcept override;
		void OnCreated(FormConcept* form) noexcept override;
		#if defined(MAX_PLATFORM_WINDOWS)
			LRESULT OnWindowMessage(FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept override;
		#endif

	private:

		std::unique_ptr<T> form_;

	};

} // namespace maxGUI

#include <maxGUI/FormModel.inl>

#endif // #ifndef MAXGUI_FORMMODEL_HPP