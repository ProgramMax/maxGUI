// Copyright 2023, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_MULTILINETEXTBOXIMPLEMENTATION_HPP
#define MAXGUI_MULTILINETEXTBOXIMPLEMENTATION_HPP

#include <string>

#include <max/Compiling/Bitmask.hpp>
#include <max/Compiling/Configuration.hpp>
#include <max/Containers/Rectangle.hpp>
#include <maxGUI/ControlWithTextImplementation.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#elif defined(MAX_PLATFORM_LINUX)
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

	class MultilineTextBoxImplementation : public ControlWithTextImplementation
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit MultilineTextBoxImplementation(HWND window_handle) noexcept;
#endif

		~MultilineTextBoxImplementation() noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
		static HWND Create(HWND parent_window_handle, max::Containers::Rectangle<int, int> rectangle, std::string text, MultilineTextBoxStyles styles = MultilineTextBoxStyles::None) noexcept;
#elif defined(MAX_PLATFORM_LINUX)
		static QTextEdit* Create(QWidget* parent_window, max::Containers::Rectangle<int, int> rectangle, std::string text, MultilineTextBoxStyles styles = MultilineTextBoxStyles::None) noexcept;
#endif

	};

} // namespace maxGUI

#endif // #ifndef MAXGUI_MULTILINETEXTBOXIMPLEMENTATION_HPP