// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_PROGRESSBAR_HPP
#define MAXGUI_PROGRESSBAR_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/Control.hpp>
#include <maxGUI/Rectangle.hpp>
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

		void SetRange(int min, int max) noexcept;
		void GetRange(int& min, int& max) noexcept;
		void SetValue(int value) noexcept;
		int GetValue() noexcept;

	};
		
	class ProgressBarFactoryImplementationDetails
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND CreateProgressBar(Rectangle rectangle, int min, int max, int value, ProgressBarStyles styles, HWND parent_window_handle) noexcept;
#elif defiend(MAX_PLATFORM_LINUX)
		static QProgressBar* CreateProgressBar(Rectangle rectangle, int min, int max, int value, ProgressBarStyles styles, QWidget* parent_window) noexcept;
#endif

	};

	template <typename ProgressBarType = ProgressBar>
	class ProgressBarFactory : public ControlFactory
	{
	public:

		ProgressBarFactory(Rectangle rectangle, int min, int max, int value) noexcept
			: ProgressBarFactory(std::move(rectangle), std::move(min), std::move(max), std::move(value), ProgressBarStyles::None)
		{}

		ProgressBarFactory(Rectangle rectangle, int min, int max, int value, ProgressBarStyles styles) noexcept
			: ControlFactory(std::move(rectangle))
			, min_(std::move(min))
			, max_(std::move(max))
			, value_(std::move(value))
			, styles_(std::move(styles))
		{}

		~ProgressBarFactory() noexcept override = default;

#if defined(MAX_PLATFORM_WINDOWS)
		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = ProgressBarFactoryImplementationDetails::CreateProgressBar(rectangle_, min_, max_, value_, styles_, std::move(parent_window_handle));
			return std::make_unique<ProgressBarType>(std::move(window_handle));
		}
#elif defined(MAX_PLATFORM_LINUX)
		std::unique_ptr<Control> CreateControl(QWidget* parent_window) const noexcept override {
			QProgressBar* progress_bar = ProgressBarFactoryImplementationDetails::CreateProgressBar(rectangle_, min_, max_, value_, styles_, std::move(parent_window));
			return std::make_unique<ProgressBarType>(std::move(progress_bar));
		}
#endif

		int min_;
		int max_;
		int value_;
		ProgressBarStyles styles_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_PROGRESSBAR_HPP
