// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_FRAME_HPP
#define MAXGUI_FRAME_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	class Frame : public ControlWithText
	{
	public:

		explicit Frame(HWND window_handle) MAX_DOES_NOT_THROW;

		~Frame() MAX_DOES_NOT_THROW override = default;

	};

	class FrameFactoryImplementationDetails
	{
	public:

		static HWND CreateFrame(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW;

	};
	
	template <typename FrameType = Frame>
	class FrameFactory : public ControlWithTextFactory
	{
	public:

		FrameFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
		{}

		~FrameFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override {
			HWND window_handle = FrameFactoryImplementationDetails::CreateFrame(text_, rectangle_, std::move(parent_window_handle));
			return std::make_unique<FrameType>(std::move(window_handle));
		}

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_FRAME_HPP