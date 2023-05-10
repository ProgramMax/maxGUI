// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_MULTILINETEXTBOX_HPP
#define MAXGUI_MULTILINETEXTBOX_HPP

#include <string>

#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/MultilineTextBoxImplementation.hpp>

#if defined(MAX_PLATFORM_LINUX)
	#include <QTextEdit>
#endif

namespace maxGUI
{

	class DefaultMultilineTextBoxBehavior {
	};
	
	template< class Behavior = DefaultMultilineTextBoxBehavior >
	class MultilineTextBox : public ControlWithText
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit MultilineTextBox(HWND window_handle) noexcept;
#elif defined(MAX_PLATFORM_LINUX)
		explicit MultilineTextBox(QTextEdit* widget) noexcept;
#endif

		~MultilineTextBox() noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, MultilineTextBoxStyles styles = MultilineTextBoxStyles::None) noexcept;
#elif defined(MAX_PLATFORM_LINUX)
		static QTextEdit* Create(QWidget* parent_window, max::Containers::Rectangle<int, int> rectangle, std::string text, MultilineTextBoxStyles styles = MultilineTextBoxStyles::None) noexcept;
#endif

	//protected:
#if defined(MAX_PLATFORM_WINDOWS)
		void OnCommand(WORD notification) noexcept override;
#endif

	private:

		Behavior behavior_;
		MultilineTextBoxImplementation implementation_;

	};

} //  namespace maxGUI

#include <maxGUI/MultilineTextBox.inl>

#endif // #ifndef MAXGUI_MULTILINETEXTBOX_HPP
