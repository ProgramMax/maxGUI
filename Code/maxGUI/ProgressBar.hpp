// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_PROGRESSBAR_HPP
#define MAXGUI_PROGRESSBAR_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/Control.hpp>
#include <maxGUI/Rectangle.hpp>
#include <utility>

namespace maxGUI
{

	class ProgressBar : public Control
	{
	public:

		explicit ProgressBar(HWND window_handle) MAX_DOES_NOT_THROW;

		~ProgressBar() MAX_DOES_NOT_THROW override = default;

	};
		
	class ProgressBarFactoryImplementationDetails
	{
	public:

		static HWND CreateProgressBar(Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW;

	};

	template <typename ProgressBarType = ProgressBar>
	class ProgressBarFactory : public ControlFactory
	{
	public:

		ProgressBarFactory(Rectangle rectangle) MAX_DOES_NOT_THROW
			: ControlFactory(std::move(rectangle))
		{}

		~ProgressBarFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override {
			HWND window_handle = ProgressBarFactoryImplementationDetails::CreateProgressBar(rectangle_, std::move(parent_window_handle));
			return std::make_unique<ProgressBarType>(std::move(window_handle));
		}

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_PROGRESSBAR_HPP