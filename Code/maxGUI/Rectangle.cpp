// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Rectangle.hpp>

#include <utility>

namespace maxGUI {

	Rectangle::Rectangle(int top, int left, int height, int width) noexcept
		: top_(std::move(top))
		, left_(std::move(left))
		, height_(std::move(height))
		, width_(std::move(width))
	{}

} // namespace maxGUI