// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Button.hpp>
#include <maxGUI/EntryPoint.hpp>
#include <maxGUI/Form.hpp>
#include <maxGUI/Label.hpp>
#include <maxGUI/Rectangle.hpp>
#include <maxGUI/TextBox.hpp>
#include <memory>
#include <utility>

class LoginButton : public maxGUI::Button
{
public:

	// TODO: Can we not need to know about HWND somehow?
	explicit LoginButton(HWND window_handle) noexcept
		: maxGUI::Button(window_handle)
	{}

	~LoginButton() noexcept override = default;

	void OnPressed() noexcept override {
		maxGUI::PostExitMessage(0);
	}

};

class LoginForm : public maxGUI::Form {
public:

	// TODO: Can we not need to know about HWND somehow?
	explicit LoginForm(HWND window_handle) noexcept
		: maxGUI::Form(window_handle)
	{}

	void OnCreated() noexcept override {
		maxGUI::LabelFactory<> welcome_label_factory(maxGUI::Rectangle(50, 50, 500, 300), "Login");
		AddControl(&welcome_label_factory);

		maxGUI::TextBoxFactory<> username_textbox_factory(maxGUI::Rectangle(100, 50, 50, 300), "");
		username_textbox_ = AddControl(&username_textbox_factory);

		// The extra optional parameter at the end is a bitmask of styles.
		// Different controls have different optional styles available.
		// For example, a TextBox can have the Password style which hides the character typed by the user.
		maxGUI::TextBoxFactory<> password_textbox_factory(maxGUI::Rectangle(150, 50, 50, 300), "", maxGUI::TextBoxStyles::Password);
		password_textbox_ = AddControl(&password_textbox_factory);

		// A Button can have the Default style, which allows the user to press Enter at any time to press the button.
		maxGUI::ButtonFactory<LoginButton> login_button_factory(maxGUI::Rectangle(250, 50, 100, 100), "Login", maxGUI::ButtonStyles::Default);
		AddControl(&login_button_factory);
	}

	maxGUI::Control* username_textbox_ = nullptr;
	maxGUI::Control* password_textbox_ = nullptr;

};

int maxGUIEntryPoint(maxGUI::FormContainer&& form_container) noexcept {
	maxGUI::FormFactory<LoginForm> login_form_factory;
	if (!form_container.CreateForm(login_form_factory, 350, 400, "Login", maxGUI::FormStyles::FixedSize)) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}