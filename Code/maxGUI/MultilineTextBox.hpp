// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_MULTILINETEXTBOX_HPP
#define MAXGUI_MULTILINETEXTBOX_HPP

#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <memory>
#include <string>

namespace maxGUI
{
	
	class MultilineTextBox : public ControlWithText
	{
	public:

		explicit MultilineTextBox(HWND window_handle) noexcept;

		~MultilineTextBox() noexcept override = default;

	};

	class MultilineTextBoxFactoryImplementationDetails
	{
	public:

		static HWND CreateMultilineTextBox(std::string text, Rectangle rectangle, HWND parent_window_handle) noexcept;

	};
	
	template <typename MultilineTextBoxType = MultilineTextBox>
	class MultilineTextBoxFactory : public ControlWithTextFactory
	{
	public:

		MultilineTextBoxFactory(Rectangle rectangle, std::string text) noexcept
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
		{}

		~MultilineTextBoxFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = MultilineTextBoxFactoryImplementationDetails::CreateMultilineTextBox(text_, rectangle_, parent_window_handle);
			return std::make_unique<MultilineTextBoxType>(std::move(window_handle));
		}

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_MULTILINETEXTBOX_HPP