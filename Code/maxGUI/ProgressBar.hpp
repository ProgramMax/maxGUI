// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_PROGRESSBAR_HPP
#define MAXGUI_PROGRESSBAR_HPP

#include <maxGUI/Control.hpp>
#include <maxGUI/Rectangle.hpp>
#include <utility>

namespace maxGUI
{

	class ProgressBar : public Control
	{
	public:

		explicit ProgressBar(HWND window_handle) noexcept;

		~ProgressBar() noexcept override = default;

		void SetRange(int min, int max) noexcept;
		void GetRange(int& min, int& max) noexcept;
		void SetValue(int value) noexcept;
		int GetValue() noexcept;

	};
		
	class ProgressBarFactoryImplementationDetails
	{
	public:

		static HWND CreateProgressBar(Rectangle rectangle, int min, int max, int value, HWND parent_window_handle) noexcept;

	};

	template <typename ProgressBarType = ProgressBar>
	class ProgressBarFactory : public ControlFactory
	{
	public:

		ProgressBarFactory(Rectangle rectangle, int min, int max, int value) noexcept
			: ControlFactory(std::move(rectangle))
			, min_(std::move(min))
			, max_(std::move(max))
			, value_(std::move(value))
		{}

		~ProgressBarFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = ProgressBarFactoryImplementationDetails::CreateProgressBar(rectangle_, min_, max_, value_, std::move(parent_window_handle));
			return std::make_unique<ProgressBarType>(std::move(window_handle));
		}

		int min_;
		int max_;
		int value_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_PROGRESSBAR_HPP