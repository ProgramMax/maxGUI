// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ProgressBar.hpp>

#include <commctrl.h>

namespace maxGUI
{
	
	ProgressBar::ProgressBar(HWND window_handle) MAX_DOES_NOT_THROW
		: Control(std::move(window_handle))
	{}
	
			
	HWND ProgressBarFactoryImplementationDetails::CreateProgressBar(Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW {
		// PBS_VERTICAL
		// PBS_SMOOTH
		return CreateWindowEx(0, PROGRESS_CLASS, TEXT(""), WS_CHILD | WS_VISIBLE, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

} //  namespace maxGUI