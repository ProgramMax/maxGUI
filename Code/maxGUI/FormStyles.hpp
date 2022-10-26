// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FORMSTYLES_HPP
#define MAXGUI_FORMSTYLES_HPP

#include <max/Compiling/Bitmask.hpp>

namespace maxGUI
{

	enum class FormStyles {
		None = 0,
		DialogBox = 1,
		FixedSize = 2,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::FormStyles);

#endif // #ifndef MAXGUI_FORMSTYLES_HPP