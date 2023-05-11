// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ControlImplementation.hpp>

#include <utility>

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	ControlImplementation::ControlImplementation(HWND window_handle) noexcept
		: window_handle_(std::move(window_handle))
	{}
#endif

	ControlImplementation::~ControlImplementation() noexcept = default;

} //  namespace maxGUI
