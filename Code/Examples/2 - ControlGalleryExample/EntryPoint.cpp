// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <max/Compiling/ThrowSpecification.hpp>
#include <maxGUI/Button.hpp>
#include <maxGUI/DropDownBox.hpp>
#include <maxGUI/EntryPoint.hpp>
#include <maxGUI/Form.hpp>
#include <maxGUI/Frame.hpp>
#include <maxGUI/Label.hpp>
#include <maxGUI/ListBox.hpp>
#include <maxGUI/MultilineTextBox.hpp>
#include <maxGUI/ProgressBar.hpp>
#include <maxGUI/RadioButton.hpp>
#include <maxGUI/Rectangle.hpp>
#include <maxGUI/TextBox.hpp>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class CustomButton : public maxGUI::Button
{
public:

	// TODO: Can we not need to know about HWND somehow?
	explicit CustomButton(HWND window_handle) MAX_DOES_NOT_THROW
		: maxGUI::Button(window_handle)
	{}

	~CustomButton() MAX_DOES_NOT_THROW override = default;

	void OnPressed() MAX_DOES_NOT_THROW override {
		maxGUI::PostExitMessage(0);
	}

};

class ControlGalleryForm : public maxGUI::Form {
public:

	// TODO: Can we not need to know about HWND somehow?
	explicit ControlGalleryForm(HWND window_handle) MAX_DOES_NOT_THROW
		: maxGUI::Form(window_handle)
	{}

	void OnCreated() MAX_DOES_NOT_THROW override {
		maxGUI::ButtonFactory<CustomButton> custom_button_factory(maxGUI::Rectangle(25, 25, 50, 150), "Custom Button");
		AddControl(&custom_button_factory);

		std::vector<std::string> dropdown_options{"Option 1", "Option 2", "Option 3"};
		maxGUI::DropDownBoxFactory<> dropdownbox_factory(maxGUI::Rectangle(100, 25, 250, 300), std::move(dropdown_options));
		AddControl(&dropdownbox_factory);

		// TODO: Add the radio buttons inside the frame
		maxGUI::FrameFactory<> frame_factory(maxGUI::Rectangle(150, 25, 50, 300), "Frame");
		AddControl(&frame_factory);

		maxGUI::LabelFactory<> label_factory(maxGUI::Rectangle(225, 25, 25, 300), "Label");
		AddControl(&label_factory);

		std::vector<std::string> listbox_options{"Item 1", "Item 2", "Item 3"};
		maxGUI::ListBoxFactory<> listbox_factory(maxGUI::Rectangle(275, 25, 150, 300), std::move(listbox_options));
		AddControl(&listbox_factory);

		maxGUI::MultilineTextBoxFactory<> multilinetextbox_factory(maxGUI::Rectangle(450, 25, 150, 300), "Multiline\r\ntextbox");
		AddControl(&multilinetextbox_factory);

		maxGUI::ProgressBarFactory<> progressbar_factory(maxGUI::Rectangle(625, 25, 25, 300));
		AddControl(&progressbar_factory);

		maxGUI::RadioButtonFactory<> radiobutton_factory(maxGUI::Rectangle(675, 25, 25, 300), "Option 1");
		AddControl(&radiobutton_factory);

		maxGUI::RadioButtonFactory<> radiobutton_factory2(maxGUI::Rectangle(700, 25, 25, 300), "Option 2");
		AddControl(&radiobutton_factory2);

		maxGUI::TextBoxFactory<> textbox_factory(maxGUI::Rectangle(750, 25, 25, 300), "Textbox");
		AddControl(&textbox_factory);
	}

};

int maxGUIEntryPoint(maxGUI::FormContainer&& form_container) MAX_DOES_NOT_THROW {
	maxGUI::FormFactory<ControlGalleryForm> control_gallery_form_factory;
	if (!form_container.CreateForm(control_gallery_form_factory, 775, 350, "Control gallery")) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}