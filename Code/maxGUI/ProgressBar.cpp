// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/ProgressBar.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#include <commctrl.h>
#endif

namespace maxGUI
{
	
#if defined(MAX_PLATFORM_WINDOWS)
	ProgressBar::ProgressBar(HWND window_handle) noexcept
		: Control(std::move(window_handle))
	{}
#elif defined(MAX_PLATFORM_LINUX)
	ProgressBar::ProgressBar(QProgressBar* widget) noexcept
		: Control()
	{}
#endif

	void ProgressBar::SetRange(int min, int max) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		SendMessage(window_handle_, PBM_SETRANGE32, static_cast<WPARAM>(min), static_cast<LPARAM>(max));
#endif
	}

	void ProgressBar::GetRange(int& min, int& max) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		PBRANGE range = {0};
		SendMessage(window_handle_, PBM_GETRANGE, TRUE, reinterpret_cast<LPARAM>(&range));
		min = range.iLow;
		max = range.iHigh;
#endif
	}

	void ProgressBar::SetValue(int value) noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		SendMessage(window_handle_, PBM_SETPOS, static_cast<WPARAM>(value), 0);
#endif
	}

	int ProgressBar::GetValue() noexcept {
#if defined(MAX_PLATFORM_WINDOWS)
		return static_cast<int>(SendMessage(window_handle_, PBM_GETPOS, 0, 0));
#elif defined(MAX_PLATFORM_LINUX)
		return 0;
#endif
	}

#if defined(MAX_PLATFORM_WINDOWS)
	HWND ProgressBarFactoryImplementationDetails::CreateProgressBar(Rectangle rectangle, int min, int max, int value, ProgressBarStyles styles, HWND parent_window_handle) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE;
		// MSVC at warning level 4 issues C26813 because it wants "if (styles & ButtonStyles::Default) {"
		// But this doesn't play nicely with enum classes because ultimately it needs to convert to bool.
		// See https://developercommunity.visualstudio.com/t/C26813-incompatible-with-enum-class/10145182
		#pragma warning(push)
		#pragma warning(disable: 26813)
		if ((styles & ProgressBarStyles::Vertical) == ProgressBarStyles::Vertical) {
			win32_styles |= PBS_VERTICAL;
		}
		if ((styles & ProgressBarStyles::Smooth) == ProgressBarStyles::Smooth) {
			win32_styles |= PBS_SMOOTH;
		}
		#pragma warning(pop)
		HWND window_handle = CreateWindowEx(0, PROGRESS_CLASS, TEXT(""), win32_styles, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);

		SendMessage(window_handle, PBM_SETRANGE32, static_cast<WPARAM>(min), static_cast<LPARAM>(max));
		SendMessage(window_handle, PBM_SETPOS, static_cast<WPARAM>(value), 0);
		
		return window_handle;
	}
#elif defined(MAX_PLATFORM_LINUX)
	QProgressBar* ProgressBarFactoryImplementationDetails::CreateProgressBar(Rectangle rectangle, int min, int max, int value, ProgressBarStyles styles, QWidget* parent_window) noexcept {
		QProgressBar* progress_bar = new QProgressBar(parent_window);
		progress_bar->setGeometry(rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_);
		progress_bar->setRange(min, max);
		progress_bar->setValue(value);
		// TODO: Handle ProgressBarStyles styles
		return progress_bar;
	}
#endif

} //  namespace maxGUI
