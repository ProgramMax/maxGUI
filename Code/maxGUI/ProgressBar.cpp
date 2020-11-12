// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ProgressBar.hpp>

#include <commctrl.h>

namespace maxGUI
{
	
	ProgressBar::ProgressBar(HWND window_handle) noexcept
		: Control(std::move(window_handle))
	{}

	void ProgressBar::SetRange(int min, int max) noexcept {
		SendMessage(window_handle_, PBM_SETRANGE32, min, max);
	}

	void ProgressBar::GetRange(int& min, int& max) noexcept {
		PBRANGE range = {0};
		SendMessage(window_handle_, PBM_GETRANGE, TRUE, reinterpret_cast<LPARAM>(&range));
		min = range.iLow;
		max = range.iHigh;
	}

	void ProgressBar::SetValue(int value) noexcept {
		SendMessage(window_handle_, PBM_SETPOS, value, 0);
	}

	int ProgressBar::GetValue() noexcept {
		return static_cast<int>(SendMessage(window_handle_, PBM_GETPOS, 0, 0));
	}

	HWND ProgressBarFactoryImplementationDetails::CreateProgressBar(Rectangle rectangle, int min, int max, int value, ProgressBarStyles styles, HWND parent_window_handle) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE;
		if ((styles & ProgressBarStyles::Vertical) == ProgressBarStyles::Vertical) {
			win32_styles |= PBS_VERTICAL;
		}
		if ((styles & ProgressBarStyles::Smooth) == ProgressBarStyles::Smooth) {
			win32_styles |= PBS_SMOOTH;
		}
		HWND window_handle = CreateWindowEx(0, PROGRESS_CLASS, TEXT(""), win32_styles, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);

		SendMessage(window_handle, PBM_SETRANGE32, min, max);
		SendMessage(window_handle, PBM_SETPOS, value, 0);
		
		return window_handle;
	}

} //  namespace maxGUI