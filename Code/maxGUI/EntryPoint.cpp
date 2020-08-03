// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/EntryPoint.hpp>

int WINAPI WinMain(HINSTANCE instance_handle, HINSTANCE /*previous_instance_handle*/, LPSTR /*command_line*/, int /*command_show*/)
{
	return maxGUIEntryPoint(maxGUI::FormContainer(instance_handle));
}

namespace maxGUI {

	void PostExitMessage(const int exit_code) noexcept {
		PostQuitMessage(exit_code);
	}

	int MessagePump(const FormContainer& form_container) noexcept {
		MSG Message = {0};
		while (GetMessage(&Message, NULL, 0, 0) > 0)
		{
			for (const auto& form : form_container.forms_) {
				if (IsDialogMessage(form->window_handle_, &Message) == 0)
				{
					//TranslateAccelerator
					TranslateMessage(&Message);
					DispatchMessage(&Message);
				}
			}
		}

		return static_cast<int>(Message.wParam);
	}

} // namespace maxGUI
