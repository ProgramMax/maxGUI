// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/Label.hpp>

#include <maxGUI/Win32String.hpp>

namespace maxGUI
{
	
	Label::Label(HWND window_handle) noexcept
		: ControlWithText(std::move(window_handle))
	{}

	HWND Label::Create(HWND parent_window_handle, Rectangle rectangle, std::string text) noexcept {
		// TODO: Probably specify WS_EX_TRANSPARENT and handle WM_ERASEBKGND...no one actually wants the non-transparent background
		Win32String win32_text = Utf8ToWin32String(std::move(text));
		return CreateWindowEx(0, TEXT("STATIC"), win32_text.text_, WS_CHILD | WS_VISIBLE, rectangle.left_, rectangle.top_, rectangle.width_, rectangle.height_, parent_window_handle, NULL, reinterpret_cast<HINSTANCE>(GetWindowLongPtr(parent_window_handle, GWLP_HINSTANCE)), NULL);
	}

	/* TODO: Write something for transparent-background labels
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint( WindowHandle, &ps);

			This->OnDrawing( hdc );

			SelectObject( hdc, (HBRUSH)GetStockObject(WHITE_BRUSH) );
			SelectObject( hdc, (HBRUSH)GetStockObject(HOLLOW_BRUSH) );

			HFONT Font = CreateFont(-20, 0, 0, 0, FW_NORMAL, 0, 0, 0,
							DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
							CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Tahoma"));
							//ANTIALIASED_QUALITY

			int iModePrev = SetBkMode( hdc, TRANSPARENT );
			HFONT hfPrev = (HFONT)SelectObject( hdc, (HGDIOBJ)Font );

			BOOL Result = TextOut( hdc, 0, 0, L"Test", 4 );
			if( Result == 0 )
			{
				// error
			}

			SelectObject( hdc, hfPrev );
			SetBkMode( hdc, iModePrev );

			DeleteObject( Font );

			EndPaint(WindowHandle, &ps);
		}
		break;
		*/
} //  namespace maxGUI