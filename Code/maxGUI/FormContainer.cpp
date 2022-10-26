// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/FormContainer.hpp>

namespace maxGUI {

	#if defined(MAX_PLATFORM_WINDOWS)
		FormContainer::FormContainer(HINSTANCE instance_handle) noexcept
			: instance_handle_(instance_handle)
		{}
	#elif defined(MAX_PLATFORM_LINUX)
		FormContainer::FormContainer(QApplication* app) noexcept
			: app_(std::move(app))
		{}
	#endif

} // namespace maxGUI