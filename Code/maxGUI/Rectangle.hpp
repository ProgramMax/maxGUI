// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_RECTANGLE_HPP
#define MAXGUI_RECTANGLE_HPP

namespace maxGUI {

	struct Rectangle {

		Rectangle(int top, int left, int height, int width) noexcept;

		int top_;
		int left_;
		int height_;
		int width_;

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_RECTANGLE_HPP