// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Button.hpp>

#include <utility>

namespace maxGUI
{
	
	Button::Button(HWND window_handle) MAX_DOES_NOT_THROW
		: Control(std::move(window_handle))
	{}

	void Button::OnPressed() MAX_DOES_NOT_THROW
	{}

	void Button::OnCommand(WORD notification) MAX_DOES_NOT_THROW {
		if (notification == BN_CLICKED)
		{
			OnPressed();
		}
	}
	
	ButtonFactory::ButtonFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW
		: rectangle_(std::move(rectangle))
		, text_(std::move(text_))
	{}

	std::unique_ptr<Control> ButtonFactory::CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW {
		// BS_DEFPUSHBUTTON
		// BS_FLAT
		HWND window_handle = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("BUTTON"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_TABSTOP, rectangle_.left_, rectangle_.top_, rectangle_.width_, rectangle_.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
		// TODO: Convert the std::string (lets go with UTF-8) into TCHAR
		//SendMessage(window_handle, WM_SETTEXT, 0, static_cast<LPARAM>(tchar_string));
		return std::make_unique<Button>(std::move(window_handle));
	}

} //  namespace maxGUI