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
		maxGUI::LabelFactory<> welcome_label_factory(maxGUI::Rectangle(50, 50, 500, 300), "Login");
		form->AddControl(&welcome_label_factory);

		maxGUI::TextBoxFactory<> username_textbox_factory(maxGUI::Rectangle(100, 50, 50, 300), "");
		username_textbox_ = form->AddControl(&username_textbox_factory);

		// The extra optional parameter at the end is a bitmask of styles.
		// Different controls have different optional styles available.
		// For example, a TextBox can have the Password style which hides the character typed by the user.
		maxGUI::TextBoxFactory<> password_textbox_factory(maxGUI::Rectangle(150, 50, 50, 300), "", maxGUI::TextBoxStyles::Password);
		password_textbox_ = form->AddControl(&password_textbox_factory);

		// A Button can have the Default style, which allows the user to press Enter at any time to press the button.
		maxGUI::ButtonFactory<maxGUI::Button<LoginButtonBehavior>> login_button_factory(maxGUI::Rectangle(250, 50, 100, 100), "Login", maxGUI::ButtonStyles::Default | maxGUI::ButtonStyles::Disabled);
		form->AddControl(&login_button_factory);
	}

	void OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
		maxGUI::PostExitMessage(0);
	}

	maxGUI::Control* username_textbox_ = nullptr;
	maxGUI::Control* password_textbox_ = nullptr;

};

int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	maxGUI::FormFactory login_form_factory(maxGUI::GetDefaultFormAllocator<LoginForm>());
	// TODO: For controls, the style goes on the factory. Forms shouldn't be different.
	if (!form_container.CreateForm(login_form_factory, 350, 400, "Login", maxGUI::FormStyles::FixedSize)) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}