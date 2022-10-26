// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/FormContainer.hpp>

namespace maxGUI {

	template <typename FormFactoryType>
	bool FormContainer::CreateForm(FormFactoryType& form_factory, int height, int width, std::string title) noexcept {
		return CreateForm(form_factory, std::move(height), std::move(width), std::move(title), FormStyles::None);
	}

	template <typename FormFactoryType>
	bool FormContainer::CreateForm(FormFactoryType& form_factory, int height, int width, std::string title, FormStyles styles) noexcept {
		form_factory.form_container_ = this;
		#if defined(MAX_PLATFORM_WINDOWS)
			return form_factory.CreateForm(instance_handle_, std::move(height), std::move(width), std::move(title), std::move(styles));
		#elif defined(MAX_PLATFORM_LINUX)
			return form_factory.CreateForm(std::move(height), std::move(width), std::move(title), std::move(styles));
		#endif
}

} // namespace maxGUI