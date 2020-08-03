// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_ENTRYPOINT_HPP
#define MAXGUI_ENTRYPOINT_HPP

#include <maxGUI/Form.hpp>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

// The user should implement this function.
// maxGUI calls this when the program begins.
int maxGUIEntryPoint(maxGUI::FormContainer&& form_container) noexcept;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow );

namespace maxGUI {

	int MessagePump(const FormContainer& form_container) noexcept;
	void PostExitMessage(int exit_code) noexcept;

} // namespace maxGUI

#endif // #ifndef MAXGUI_ENTRYPOINT_HPP