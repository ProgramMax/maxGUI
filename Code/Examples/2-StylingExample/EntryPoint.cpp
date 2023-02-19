// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <memory>
#include <utility>

#include <maxGUI/maxGUI.hpp>

// TODO: Add text changed handlers to the username and password fields.
// Enable the login button if they are both not empty.

class LoginButtonBehavior
{
public:

	static void OnPressed() noexcept {
		maxGUI::PostExitMessage(0);
	}

};

class LoginForm {
public:

	void OnCreated(maxGUI::FormConcept* form) noexcept {
		form->AddControl<maxGUI::Label>(maxGUI::Rectangle(50, 50, 500, 300), "Login");

		username_textbox_ = form->AddControl<maxGUI::TextBox>(maxGUI::Rectangle(100, 50, 50, 300), "");

		// The extra optional parameter at the end is a bitmask of styles.
		// Different controls have different optional styles available.
		// For example, a TextBox can have the Password style which hides the character typed by the user.
		password_textbox_ = form->AddControl<maxGUI::TextBox>(maxGUI::Rectangle(150, 50, 50, 300), "", maxGUI::TextBoxStyles::Password);

		// A Button can have the Default style, which allows the user to press Enter at any time to press the button.
		form->AddControl<maxGUI::Button<LoginButtonBehavior>>(maxGUI::Rectangle(250, 50, 100, 100), "Login", maxGUI::ButtonStyles::Default | maxGUI::ButtonStyles::Disabled);
	}

	void OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
		maxGUI::PostExitMessage(0);
	}

	maxGUI::TextBox* username_textbox_ = nullptr;
	maxGUI::TextBox* password_textbox_ = nullptr;

};

int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	maxGUI::FormFactory login_form_factory(maxGUI::GetDefaultFormAllocator<LoginForm>());
	// TODO: For controls, the style goes on the factory. Forms shouldn't be different.
	if (!form_container.CreateForm(login_form_factory, 350, 400, "Login", maxGUI::FormStyles::FixedSize)) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}