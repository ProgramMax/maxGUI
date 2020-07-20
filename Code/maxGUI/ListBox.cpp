// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ListBox.hpp>

#include <utility>

namespace maxGUI
{
	
	ListBox::ListBox(HWND window_handle) MAX_DOES_NOT_THROW
		: Control(std::move(window_handle))
	{}

	HWND ListBoxFactoryImplementationDetails::CreateListBox(Rectangle rectangle, std::vector<std::string> list, HWND parent_window_handle) MAX_DOES_NOT_THROW {
		// LBS_MULTIPLESEL
		// LBS_EXTENDEDSEL
		return CreateWindowEx(0, TEXT("LISTBOX"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_TABSTOP | LBS_STANDARD, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI