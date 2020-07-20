// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_MULTILINETEXTBOX_HPP
#define MAXGUI_MULTILINETEXTBOX_HPP

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/ControlWithText.hpp>
#include <maxGUI/Rectangle.hpp>
#include <memory>
#include <string>

namespace maxGUI
{
	
	class MultilineTextBox : public ControlWithText
	{
	public:

		explicit MultilineTextBox(HWND window_handle) MAX_DOES_NOT_THROW;

		~MultilineTextBox() MAX_DOES_NOT_THROW override = default;

	};
	
	class MultilineTextBoxFactory : public ControlWithTextFactory
	{
	public:

		MultilineTextBoxFactory(Rectangle rectangle, std::string text) MAX_DOES_NOT_THROW;

		~MultilineTextBoxFactory() MAX_DOES_NOT_THROW override = default;

		std::unique_ptr<Control> CreateControl(HWND parent_window_handle) const MAX_DOES_NOT_THROW override;

	};

} //  namespace maxGUI

#endif // #ifndef MAXGUI_MULTILINETEXTBOX_HPP