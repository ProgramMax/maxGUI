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

namespace maxGUI
{

	class FormContainer {
	public:

		#if defined(MAX_PLATFORM_WINDOWS)
				explicit FormContainer(HINSTANCE instance_handle) noexcept;
		#elif defined(MAX_PLATFORM_LINUX)
				explicit FormContainer(QApplication* app) noexcept;
		#endif

		template <typename FormFactoryType>
		bool CreateForm(FormFactoryType& form_factory, int width, int height, std::string title) noexcept;

		template <typename FormFactoryType>
		bool CreateForm(FormFactoryType& form_factory, int width, int height, std::string title, FormStyles styles) noexcept;

		std::vector<std::unique_ptr<FormConcept>> forms_;

		#if defined(MAX_PLATFORM_WINDOWS)
			HINSTANCE instance_handle_;
		#elif defined(MAX_PLATFORM_LINUX)
			QApplication* app_;
		#endif

	};

} // namespace maxGUI

#include <maxGUI/FormContainer.inl>

#endif // #ifndef MAXGUI_FORMCONTAINER_HPP