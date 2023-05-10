// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/MultilineTextBoxImplementation.hpp>

#include <utility>

#if defined(MAX_PLATFORM_WINDOWS)
	#include <maxGUI/Win32String.hpp>
#endif

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	MultilineTextBoxImplementation::MultilineTextBoxImplementation(HWND window_handle) noexcept
		: ControlWithTextImplementation(std::move(window_handle))
	{}
#endif

	MultilineTextBoxImplementation::~MultilineTextBoxImplementation() noexcept = default;

#if defined(MAX_PLATFORM_WINDOWS)
	HWND MultilineTextBoxImplementation::Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, MultilineTextBoxStyles styles) noexcept {
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
		return CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), win32_text.text_, win32_styles, rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}
#elif defined(MAX_PLATFORM_LINUX)
	QTextEdit* MultilineTextBoxImplementation::Create(QWidget* parent_window, max::Containers::Rectangle<int, int> rectangle, std::string text, MultilineTextBoxStyles styles) noexcept {
		QTextEdit* multiline_textbox = new QTextEdit(text.c_str(), parent_window);
		multiline_textbox->setGeometry(rectangle.TopLeft.X(), rectangle.TopLeft.Y(), rectangle.Width, rectangle.Height);
		// TODO: Handle MultilineTextBoxStyles styles
		return multiline_textbox;
	}
#endif

} // namespace maxGUI