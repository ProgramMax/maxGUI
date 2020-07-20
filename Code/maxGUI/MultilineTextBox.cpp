// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/MultilineTextBox.hpp>

#include <utility>

namespace maxGUI
{
	
	MultilineTextBox::MultilineTextBox(HWND window_handle) MAX_DOES_NOT_THROW
		: ControlWithText(std::move(window_handle))
	{}

	HWND MultilineTextBoxFactoryImplementationDetails::CreateMultilineTextBox(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW {
		return CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | WS_TABSTOP | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL | ES_AUTOHSCROLL, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI