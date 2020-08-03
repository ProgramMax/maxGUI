// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ControlWithList.hpp>

#include <utility>

namespace maxGUI
{

	ControlWithList::ControlWithList(HWND window_handle) noexcept
		: Control(std::move(window_handle))
	{}

	void ControlWithList::OnSelectionChanged(int /*newly_selected_index*/) noexcept
	{}

	ControlWithListFactory::ControlWithListFactory(Rectangle rectangle, std::vector<std::string> list) noexcept
		: ControlFactory(std::move(rectangle))
		, list_(std::move(list))
	{}

} // namespace maxGUI