// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_MULTILINETEXTBOX_HPP
#define MAXGUI_MULTILINETEXTBOX_HPP

#include <max/Compiling/Configuration.hpp>
#include <max/Compiling/Bitmask.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <memory>
#include <string>

#if defined(MAX_PLATFORM_LINUX)
	#include <QTextEdit>
#endif

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

#if defined(MAX_PLATFORM_WINDOWS)
		explicit MultilineTextBox(HWND window_handle) noexcept;
#elif defined(MAX_PLATFORM_LINUX)
		explicit MultilineTextBox(QTextEdit* widget) noexcept;
#endif
		~MultilineTextBox() noexcept override = default;

	};

	class MultilineTextBoxFactoryImplementationDetails
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND CreateMultilineTextBox(std::string text, Rectangle rectangle, MultilineTextBoxStyles styles, HWND parent_window_handle) noexcept;
#elif defined(MAX_PLATFORM_LINUX)
		static QTextEdit* CreateMultilineTextBox(std::string text, Rectangle rectangle, MultilineTextBoxStyles styles, QWidget* parent_window) noexcept;
#endif

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

#if defined(MAX_PLATFORM_WINDOWS)
		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const noexcept override {
			HWND window_handle = MultilineTextBoxFactoryImplementationDetails::CreateMultilineTextBox(text_, rectangle_, styles_, parent_window_handle);
			return std::make_unique<MultilineTextBoxType>(std::move(window_handle));
		}
#elif defined(MAX_PLATFORM_LINUX)
		std::unique_ptr<Control> CreateControl(QWidget* parent_window) const noexcept override {
			QTextEdit* widget = MultilineTextBoxFactoryImplementationDetails::CreateMultilineTextBox(text_, rectangle_, styles_, parent_window);
			return std::make_unique<MultilineTextBoxType>(std::move(widget));
		}
#endif

	private:

		MultilineTextBoxStyles styles_;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_MULTILINETEXTBOX_HPP
