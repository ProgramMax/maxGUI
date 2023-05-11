// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include <maxGUI/maxGUI.hpp>

class CustomMultilineTextBoxBehavior {
public:

	static void OnGainedFocus(maxGUI::MultilineTextBoxImplementation* foo) noexcept {
		foo->SetText("gained");
	}

	static void OnLostFocus(maxGUI::MultilineTextBoxImplementation* foo) noexcept {
		foo->SetText("lost");
	}

};

class CustomTextBoxBehavior {
public:

	static void OnGainedFocus(maxGUI::TextBoxImplementation* foo) noexcept {
		foo->SetText("gained");
	}

	static void OnLostFocus(maxGUI::TextBoxImplementation* foo) noexcept {
		foo->SetText("lost");
	}

};

class CustomCheckBoxBehavior {
public:

	static void OnGainedFocus(maxGUI::CheckBoxImplementation* foo) noexcept {
		foo->SetText("gained");
	}

	static void OnLostFocus(maxGUI::CheckBoxImplementation* foo) noexcept {
		foo->SetText("lost");
	}

};

class CustomDropDownBoxBehavior {
public:

	static void OnGainedFocus(maxGUI::DropDownBoxImplementation* foo) noexcept {
		foo->SetText("gained");
	}

	static void OnLostFocus(maxGUI::DropDownBoxImplementation* foo) noexcept {
		foo->SetText("lost");
	}

};

class CustomListBoxBehavior {
public:

	static void OnGainedFocus(maxGUI::ListBoxImplementation* foo) noexcept {
		// TODO: Find a way to test this
		(void)foo;
	}

	static void OnLostFocus(maxGUI::ListBoxImplementation* foo) noexcept {
		// TODO: Find a way to test this
		(void)foo;
	}

};

class CustomRadioButtonBehavior {
public:

	static void OnGainedFocus(maxGUI::RadioButtonImplementation* foo) noexcept {
		foo->SetText("gained");
	}

	static void OnLostFocus(maxGUI::RadioButtonImplementation* foo) noexcept {
		foo->SetText("lost");
	}

};

class CustomButtonBehavior {
public:

	static void OnGainedFocus(maxGUI::ButtonImplementation* foo) noexcept {
		foo->SetText("gained");
	}

	static void OnLostFocus(maxGUI::ButtonImplementation* foo) noexcept {
		foo->SetText("lost");
	}

	static void OnPressed() noexcept {
		maxGUI::PostExitMessage(0);
	}

};


class ControlGalleryForm {
public:

	void OnCreated(maxGUI::FormConcept* form) noexcept {
		form->AddControl<maxGUI::Button<CustomButtonBehavior>>(max::Containers::MakeRectangle(25, 25, 150, 50), "Custom Button");

		std::vector<std::string> dropdown_options{"Option 1", "Option 2", "Option 3"};
		form->AddControl<maxGUI::DropDownBox<CustomDropDownBoxBehavior>>(max::Containers::MakeRectangle(25, 100, 300, 250), std::move(dropdown_options));

		// TODO: Add the radio buttons inside the frame
		form->AddControl<maxGUI::Frame>(max::Containers::MakeRectangle(25, 150, 300, 50), "Frame");

		form->AddControl<maxGUI::Label>(max::Containers::MakeRectangle(25, 225, 300, 25), "Label");

		std::vector<std::string> listbox_options{"Item 1", "Item 2", "Item 3"};
		form->AddControl<maxGUI::ListBox<CustomListBoxBehavior>>(max::Containers::MakeRectangle(25, 275, 300, 150), std::move(listbox_options));

		form->AddControl<maxGUI::MultilineTextBox<CustomMultilineTextBoxBehavior>>(max::Containers::MakeRectangle(25, 450, 300, 150), "Multiline\r\ntextbox");

		form->AddControl<maxGUI::ProgressBar>(max::Containers::MakeRectangle(25, 625, 300, 25), 0, 100, 50);

		form->AddControl<maxGUI::CheckBox<CustomCheckBoxBehavior>>(max::Containers::MakeRectangle(25, 675, 300, 25), "Check 1");

		// When using multiple RadioButtons that belong to one group, be sure to add the FirstInGroup style to the first option.
		form->AddControl<maxGUI::RadioButton<CustomRadioButtonBehavior>>(max::Containers::MakeRectangle(25, 725, 300, 25), "Option 1", maxGUI::RadioButtonStyles::FirstInGroup);

		form->AddControl<maxGUI::RadioButton<CustomRadioButtonBehavior>>(max::Containers::MakeRectangle(25, 750, 300, 25), "Option 2");

		form->AddControl<maxGUI::TextBox<CustomTextBoxBehavior>>(max::Containers::MakeRectangle(25, 800, 300, 25), "Textbox");
	}

	void OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
		maxGUI::PostExitMessage(0);
	}

};


int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	auto form_allocator = maxGUI::GetDefaultFormAllocator<ControlGalleryForm>();
	if (!form_container.CreateForm<ControlGalleryForm>(350, 825, "Control gallery", form_allocator.get(), maxGUI::FormStyles::FixedSize)) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}