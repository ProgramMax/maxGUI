// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <memory>
#include <utility>

#include <maxGUI/maxGUI.hpp>

// TODO: Add text changed handlers to the username and password fields.
// Enable the login button if they are both not empty.

namespace {

	bool is_username_empty = true;
	bool is_password_empty = true;

} // anonymous namespace

class UsernameTextboxBehavior {
public:

	static void OnLostFocus(maxGUI::TextBoxImplementation* textbox) noexcept {
		is_username_empty = textbox->GetText().length() == 0;

		if (!is_username_empty && !is_password_empty) {
			//login_button_->SetStyle(enabled);
		} else {
			//login_button_->SetStyle(disabled);
		}
	}

};

class PasswordTextboxBehavior {
public:

	static void OnLostFocus(maxGUI::TextBoxImplementation* textbox) noexcept {
		is_password_empty = textbox->GetText().length() == 0;

		if (!is_username_empty && !is_password_empty) {
			//login_button_->SetStyle(enabled);
		} else {
			//login_button_->SetStyle(disabled);
		}
	}

};

class LoginButtonBehavior {
public:

	static void OnPressed() noexcept {
		maxGUI::PostExitMessage(0);
	}

};

class LoginForm {
private:

	using UsernameTextboxType = maxGUI::TextBox<UsernameTextboxBehavior>;
	using PasswordTextboxType = maxGUI::TextBox<PasswordTextboxBehavior>;
	using LoginButtonType = maxGUI::Button<LoginButtonBehavior>;

public:

	void OnCreated(maxGUI::FormConcept* form) noexcept {
		form->AddControl<maxGUI::Label>(max::Containers::MakeRectangle(50, 50, 300, 500), "Login");

		username_textbox_ = form->AddControl<UsernameTextboxType>(max::Containers::MakeRectangle(50, 100, 300, 50), "");

		// The extra optional parameter at the end is a bitmask of styles.
		// Different controls have different optional styles available.
		// For example, a TextBox can have the Password style which hides the character typed by the user.
		password_textbox_ = form->AddControl<PasswordTextboxType>(max::Containers::MakeRectangle(50, 150, 300, 50), "", maxGUI::TextBoxStyles::Password);

		// A Button can have the Default style, which allows the user to press Enter at any time to press the button.
		login_button_ = form->AddControl<LoginButtonType>(max::Containers::MakeRectangle(50, 250, 100, 100), "Login", maxGUI::ButtonStyles::Default | maxGUI::ButtonStyles::Disabled);
	}

	void OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
		maxGUI::PostExitMessage(0);
	}

private:

	UsernameTextboxType* username_textbox_ = nullptr;
	PasswordTextboxType* password_textbox_ = nullptr;
	LoginButtonType* login_button_ = nullptr;

};


int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	auto form_allocator = maxGUI::GetDefaultFormAllocator<LoginForm>();
	if (!form_container.CreateForm<LoginForm>(400, 350, "Login", form_allocator.get(), maxGUI::FormStyles::FixedSize)) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}