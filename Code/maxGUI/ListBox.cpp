// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ListBox.hpp>

#include <utility>

namespace maxGUI
{
	
	ListBox::ListBox(HWND window_handle) noexcept
		: ControlWithList(std::move(window_handle))
	{}

	void ListBox::OnCommand(WORD notification) noexcept {
		if (notification == LBN_SELCHANGE)
		{
			int index = static_cast<int>(SendMessage(window_handle_, LB_GETCURSEL, 0, 0));
			OnSelectionChanged(index);
		}
	}

	HWND ListBoxFactoryImplementationDetails::CreateListBox(Rectangle rectangle, std::vector<std::string> list, HWND parent_window_handle) noexcept {
		// LBS_MULTIPLESEL
		// LBS_EXTENDEDSEL
		return CreateWindowEx(0, TEXT("LISTBOX"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_TABSTOP | LBS_STANDARD, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI