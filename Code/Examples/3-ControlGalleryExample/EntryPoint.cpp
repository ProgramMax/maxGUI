// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include <maxGUI/maxGUI.hpp>

class CustomButtonBehavior
{
public:

	static void OnPressed() noexcept {
		maxGUI::PostExitMessage(0);
	}

};

class ControlGalleryForm {
public:

	void OnCreated(maxGUI::FormConcept* form) noexcept {
		maxGUI::ButtonFactory<maxGUI::Button<CustomButtonBehavior>> custom_button_factory(maxGUI::Rectangle(25, 25, 50, 150), "Custom Button");
		form->AddControl(&custom_button_factory);

		std::vector<std::string> dropdown_options{"Option 1", "Option 2", "Option 3"};
		maxGUI::DropDownBoxFactory<> dropdownbox_factory(maxGUI::Rectangle(100, 25, 250, 300), std::move(dropdown_options));
		form->AddControl(&dropdownbox_factory);

		// TODO: Add the radio buttons inside the frame
		maxGUI::FrameFactory<> frame_factory(maxGUI::Rectangle(150, 25, 50, 300), "Frame");
		form->AddControl(&frame_factory);

		maxGUI::LabelFactory<> label_factory(maxGUI::Rectangle(225, 25, 25, 300), "Label");
		form->AddControl(&label_factory);

		std::vector<std::string> listbox_options{"Item 1", "Item 2", "Item 3"};
		maxGUI::ListBoxFactory<> listbox_factory(maxGUI::Rectangle(275, 25, 150, 300), std::move(listbox_options));
		form->AddControl(&listbox_factory);

		maxGUI::MultilineTextBoxFactory<> multilinetextbox_factory(maxGUI::Rectangle(450, 25, 150, 300), "Multiline\r\ntextbox");
		form->AddControl(&multilinetextbox_factory);

		maxGUI::ProgressBarFactory<> progressbar_factory(maxGUI::Rectangle(625, 25, 25, 300), 0, 100, 50);
		form->AddControl(&progressbar_factory);

		maxGUI::CheckBoxFactory<> checkbox_factory(maxGUI::Rectangle(675, 25, 25, 300), "Check 1");
		form->AddControl(&checkbox_factory);

		// When using multiple RadioButtons that belong to one group, be sure to add the FirstInGroup style to the first option.
		maxGUI::RadioButtonFactory<> radiobutton_factory(maxGUI::Rectangle(725, 25, 25, 300), "Option 1", maxGUI::RadioButtonStyles::FirstInGroup);
		form->AddControl(&radiobutton_factory);

		maxGUI::RadioButtonFactory<> radiobutton_factory2(maxGUI::Rectangle(750, 25, 25, 300), "Option 2");
		form->AddControl(&radiobutton_factory2);

		maxGUI::TextBoxFactory<> textbox_factory(maxGUI::Rectangle(800, 25, 25, 300), "Textbox");
		form->AddControl(&textbox_factory);
	}

	void OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
		maxGUI::PostExitMessage(0);
	}

};

int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	maxGUI::FormFactory control_gallery_form_factory(maxGUI::GetDefaultFormAllocator<ControlGalleryForm>());
	if (!form_container.CreateForm(control_gallery_form_factory, 825, 350, "Control gallery", maxGUI::FormStyles::FixedSize)) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}