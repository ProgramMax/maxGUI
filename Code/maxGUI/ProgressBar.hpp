// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_PROGRESSBAR_HPP
#define MAXGUI_PROGRESSBAR_HPP

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)

#include <max/Compiling/Configuration.hpp>
#include <max/Compiling/Bitmask.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/Control.hpp>
#include <utility>

#if defined(MAX_PLATFORM_LINUX)
	#include <QProgressBar>
#endif

namespace maxGUI
{

	enum class ProgressBarStyles {
		None = 0,
		Vertical = 1,
		Smooth = 2,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::ProgressBarStyles);

namespace maxGUI
{

	class ProgressBar : public Control
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit ProgressBar(HWND window_handle) noexcept;
#elif defined(MAX_PLATFORM_LINUX)
		explicit ProgressBar(QProgressBar* widget) noexcept;
#endif

		~ProgressBar() noexcept override = default;

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, int min, int max, int value, ProgressBarStyles styles = ProgressBarStyles::None) noexcept;
#elif defiend(MAX_PLATFORM_LINUX)
		static QProgressBar* Create(QWidget* parent_window, max::Containers::Rectangle<int, int> rectangle, int min, int max, int value, ProgressBarStyles styles = ProgressBarStyles::None) noexcept;
#endif

		void SetRange(int min, int max) noexcept;
		void GetRange(int& min, int& max) noexcept;
		void SetValue(int value) noexcept;
		int GetValue() noexcept;

	};

} //  namespace maxGUI

#endif // #if defined(MAX_PLATFORM_WINDOWS)

#endif // #ifndef MAXGUI_PROGRESSBAR_HPP
