// Copyright 2019, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_ENTRYPOINT_HPP
#define MAXGUI_ENTRYPOINT_HPP

#include <max/Compiling/Configuration.hpp>
#include <maxGUI/FormContainer.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
	#endif
	#include <Windows.h>

	// This instructs Microsoft Visual C++ 2005 and later to use ComCtl32.dll version 6.
	// That gives the modern visual styles.
	#pragma comment(linker,"\"/manifestdependency:type='win32' \
	name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
	processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

	#pragma comment(lib, "Dwmapi.lib")
#endif

// The user should implement this function.
// maxGUI calls this when the program begins.
int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
	int
	#if !defined(_MAC)
		#if defined(_M_CEE_PURE)
			__clrcall
		#else
			WINAPI
		#endif
	#else
		CALLBACK
	#endif
	WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd);
#endif

namespace maxGUI {

	int MessagePump(const FormContainer& form_container) noexcept;
	void PostExitMessage(int exit_code) noexcept;

} // namespace maxGUI

#endif // #ifndef MAXGUI_ENTRYPOINT_HPP
