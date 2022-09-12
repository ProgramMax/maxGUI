// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_MULTILINETEXTBOX_HPP
#define MAXGUI_MULTILINETEXTBOX_HPP

#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <memory>
#include <string>

namespace maxGUI
{

	enum class MultilineTextBoxStyles : uint8_t {
		None = 0,
		Disabled = 1,
	};

} // namespace maxGUI

MAX_BITMASKABLE_ENUM_CLASS(maxGUI::MultilineTextBoxStyles);

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

		static HWND CreateMultilineTextBox(std::string text, Rectangle rectangle, MultilineTextBoxStyles styles, HWND parent_window_handle) noexcept;

	};
	
	template <typename MultilineTextBoxType = MultilineTextBox>
	class MultilineTextBoxFactory : public ControlWithTextFactory
	{
	public:

		MultilineTextBoxFactory(Rectangle rectangle, std::string text) noexcept
			: MultilineTextBoxFactory(std::move(rectangle), std::move(text), MultilineTextBoxStyles::None)
		{}

		MultilineTextBoxFactory(Rectangle rectangle, std::string text, MultilineTextBoxStyles styles) noexcept
			: ControlWithTextFactory(std::move(rectangle), std::move(text))
			, styles_(std::move(styles))
		{}

		~MultilineTextBoxFactory() noexcept override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = MultilineTextBoxFactoryImplementationDetails::CreateMultilineTextBox(text_, rectangle_, styles_, parent_window_handle);
			return std::make_unique<MultilineTextBoxType>(std::move(window_handle));
		}

	private:

		MultilineTextBoxStyles styles_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_MULTILINETEXTBOX_HPP