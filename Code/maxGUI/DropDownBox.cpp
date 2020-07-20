// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/DropDownBox.hpp>

namespace maxGUI
{
	
	DropDownBox::DropDownBox(HWND window_handle) MAX_DOES_NOT_THROW
		: Control(std::move(window_handle))
	{}
	
	HWND DropDownBoxFactoryImplementationDetails::CreateDropDownBox(Rectangle rectangle, std::vector<std::string> list, HWND parent_window_handle) MAX_DOES_NOT_THROW {
		return CreateWindowEx(0, TEXT("COMBOBOX"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWNLIST, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	};

} //  namespace maxGUI