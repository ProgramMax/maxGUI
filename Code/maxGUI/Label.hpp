// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_LABEL_HPP
#define MAXGUI_LABEL_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <string>
#include <utility>

namespace maxGUI
{

	class Label : public ControlWithText
	{
	public:

		explicit Label(HWND window_handle) MAX_DOES_NOT_THROW;

		~Label() MAX_DOES_NOT_THROW override = default;

	};

	class LabelFactoryImplementationDetails
	{
	public:

		static HWND CreateLabel(std::string text, Rectangle rectangle, HWND parent_window_handle) MAX_DOES_NOT_THROW;

	};
	
	template <typename LabelType = Label>
	class LabelFactory : public ControlWithTextFactory
	{
	public:

		LabelFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
		{}

		~LabelFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override {
			HWND window_handle = LabelFactoryImplementationDetails::CreateLabel(text_, rectangle_, std::move(parent_window_handle));
			return std::make_unique<LabelType>(std::move(window_handle));
		}

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_LABEL_HPP