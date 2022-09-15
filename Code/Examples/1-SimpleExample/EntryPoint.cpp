// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Include both max and maxGUI in your project's libraries & include paths.
#include <maxGUI/Form.hpp>
#include <maxGUI/EntryPoint.hpp>
#include <maxGUI/MultilineTextBox.hpp>
#include <maxGUI/Rectangle.hpp>

// Create a custom form that implements the behavior you want.
class CustomForm {
public:

	void OnCreated(maxGUI::FormConcept* form) noexcept {
		// Add controls inside the Form's OnCreated().
		maxGUI::MultilineTextBoxFactory<> multiline_textbox_factory(maxGUI::Rectangle(0, 0, 100, 100), "Multi-line\r\ntest");
		multiline_textbox_ = form->AddControl(&multiline_textbox_factory);
	}

	void OnResized(maxGUI::FormConcept* /*form*/, int new_height, int new_width) noexcept {
		// In this example, make the multiline textbox take the entire area.
		multiline_textbox_->Move(maxGUI::Rectangle(0, 0, new_height, new_width));
	}

	void OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
		maxGUI::PostExitMessage(0);
	}

	maxGUI::Control* multiline_textbox_ = nullptr;
};

// Name your function EXACTLY this, keep it in the global namespace, and make sure it has noexcept.
// If you get a linker error of an unresolved external symbol for maxGUIEntryPoint(), you did this wrong.
int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	// Create the form
	maxGUI::FormFactory custom_form_factory(maxGUI::GetDefaultFormAllocator<CustomForm>());
	// TODO: It is weird that the FormContainer has the CreateForm function instead of the FormFactory.
	// Controls are similar. form.AddControl(factory). Maybe that is okay since it is "add" not "create"?
	if (!form_container.CreateForm(custom_form_factory, 400, 600, "Simple Example")) {
		return -1;
	}
	// IMPORTANT: Keep the form factory alive long enough for the form to be created by the message pump
	// In this example, the form factory's lifetime ends at the } after the message pump has exited.
	// You could choose to use the form's OnCreated() if you wanted.

	// The message pump will loop until we call maxGUI::PostExitMessage(), which is the default behavior
	// when a form is closed.
	return maxGUI::MessagePump(form_container);
}
