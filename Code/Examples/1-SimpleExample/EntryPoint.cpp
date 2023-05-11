// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Include both max and maxGUI in your project's libraries & include paths.
#include <maxGUI/maxGUI.hpp>

// Create a custom form that implements the behavior you want.
class CustomForm {
public:

	void OnCreated(maxGUI::FormConcept* form) noexcept {
		// Add controls inside the Form's OnCreated().
		multiline_textbox_ = form->AddControl<maxGUI::MultilineTextBox<>>(max::Containers::MakeRectangle(0, 0, 100, 100), "Multi-line" MAXGUI_PLATFORM_NEWLINE "test");
	}

	void OnResized(maxGUI::FormConcept* /*form*/, int new_width, int new_height) noexcept {
		// In this example, make the multiline textbox take the entire area.
		multiline_textbox_->Move(max::Containers::MakeRectangle(0, 0, new_width, new_height));
	}

	void OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
		// Post an "exit" message to the message pump to close the program.
		maxGUI::PostExitMessage(0);
	}

	maxGUI::MultilineTextBox<>* multiline_textbox_ = nullptr;
};


// Name your function EXACTLY this, keep it in the global namespace, and make sure it has noexcept.
// If you get a linker error of an unresolved external symbol for maxGUIEntryPoint(), you did this wrong.
int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	// Create the form
	auto form_allocator = maxGUI::GetDefaultFormAllocator<CustomForm>();
	if (!form_container.CreateForm<CustomForm>(600, 400, "Simple Example", form_allocator.get())) {
		return -1;
	}

	// The message pump will loop until we call maxGUI::PostExitMessage().
	return maxGUI::MessagePump(form_container);
}
