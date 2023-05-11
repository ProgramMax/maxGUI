// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_MAXGUI_HPP
#define MAXGUI_MAXGUI_HPP

#include <maxGUI/Button.hpp>
#include <maxGUI/CheckBox.hpp>
#include <maxGUI/DropDownBox.hpp>
#include <maxGUI/EntryPoint.hpp>
#include <maxGUI/FormAllocatorConcept.hpp>
#include <maxGUI/FormAllocatorModel.hpp>
#include <maxGUI/FormConcept.hpp>
#include <maxGUI/FormContainer.hpp>
#include <maxGUI/Frame.hpp>
#include <maxGUI/Label.hpp>
#include <maxGUI/ListBox.hpp>
#include <maxGUI/Menu.hpp>
#include <maxGUI/MultilineTextBox.hpp>
#include <maxGUI/ProgressBar.hpp>
#include <maxGUI/RadioButton.hpp>
#include <maxGUI/TextBox.hpp>

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#define MAXGUI_PLATFORM_NEWLINE "\r\n"

	constexpr int MAXGUI_CONTENT_PADDING = 16;
	constexpr int MAXGUI_SECTION_PADDING = 12;
	constexpr int MAXGUI_CONTROL_PADDING = 8;
#elif defined(MAX_PLATFORM_LINUX)
	#define MAXGUI_PLATFORM_NEWLINE "\n"
#endif

#endif // #ifndef MAXGUI_MAXGUI_HPP