// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/MultilineTextBox.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#include <maxGUI/Win32String.hpp>
#endif

#include <utility>

namespace maxGUI
{
	
#if defined(MAX_PLATFORM_WINDOWS)
	MultilineTextBox::MultilineTextBox(HWND window_handle) noexcept
		: ControlWithText(std::move(window_handle))
	{}
#elif defined(MAX_PLATFORM_LINUX)
	MultilineTextBox::MultilineTextBox(QTextEdit* widget) noexcept
		: ControlWithText(std::move(widget))
	{}
#endif

#if defined(MAX_PLATFORM_WINDOWS)
	HWND MultilineTextBoxFactoryImplementationDetails::CreateMultilineTextBox(std::string text, Rectangle rectangle, MultilineTextBoxStyles styles, HWND parent_window_handle) noexcept {
		DWORD win32_styles = WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | WS_TABSTOP | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL | ES_AUTOHSCROLL;
		// MSVC at warning level 4 issues C26813 because it wants "if (styles & ButtonStyles::Default) {"
		// But this doesn't play nicely with enum classes because ultimately it needs to convert to bool.
		// See https://developercommunity.visualstudio.com/t/C26813-incompatible-with-enum-class/10145182
		#pragma warning(push)
		#pragma warning(disable: 26813)
		if ((styles & MultilineTextBoxStyles::Disabled) == MultilineTextBoxStyles::Disabled) {
			win32_styles |= WS_DISABLED;
		}
		#pragma warning(pop)
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), win32_text.text_, win32_styles, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}
#elif defined(MAX_PLATFORM_LINUX)
	QTextEdit* MultilineTextBoxFactoryImplementationDetails::CreateMultilineTextBox(std::string text, Rectangle rectangle, MultilineTextBoxStyles styles, QWidget* parent_window) noexcept {
		QTextEdit* multiline_textbox = new QTextEdit(text.c_str(), parent_window);
		multiline_textbox->setGeometry(rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_);
		// TODO: Handle MultilineTextBoxStyles styles
		return multiline_textbox;
	}
#endif

} //  namespace maxGUI
