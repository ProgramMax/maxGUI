// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ControlWithList.hpp>

#include <utility>

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	ControlWithList::ControlWithList(HWND window_handle) noexcept
		: Control(std::move(window_handle))
	{}
#endif

	void ControlWithList::OnSelectionChanged(int /*newly_selected_index*/) noexcept
	{}

} // namespace maxGUI