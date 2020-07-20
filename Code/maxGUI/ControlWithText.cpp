// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ControlWithText.hpp>

#include <utility>

namespace maxGUI
{

	ControlWithText::ControlWithText(HWND window_handle) MAX_DOES_NOT_THROW
		: Control(std::move(window_handle))
	{}

	std::string ControlWithText::GetText() const MAX_DOES_NOT_THROW {
		// TODO: Impelement
		return "";
	}

	void ControlWithText::SetText(std::string text) MAX_DOES_NOT_THROW {
		// TODO: Implement
	}

	ControlWithTextFactory::ControlWithTextFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW
		: ControlFactory(std::move(rectangle))
		, text_(std::move(text))
	{}

} // namespace maxGUI