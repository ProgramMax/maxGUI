// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/EntryPoint.hpp>
#include <maxGUI/Form.hpp>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

class ControlGalleryForm : public maxGUI::Form {
public:

	// TODO: Can we not need to know about HWND somehow?
	explicit ControlGalleryForm(HWND window_handle) noexcept
		: maxGUI::Form(window_handle)
	{}

	LRESULT OnWindowMessage(UINT message, WPARAM wparam, LPARAM lparam) noexcept override {
		switch (message) {
		case WM_ERASEBKGND:
			return FALSE; // defer erasing into WM_PAINT
		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				BeginPaint(window_handle_, &ps);
				
				//ps.hdc, &ps.rcPaint, ps.fErase
				int width = ps.rcPaint.right - ps.rcPaint.left;
				int height = ps.rcPaint.bottom - ps.rcPaint.top;
				HBITMAP bitmap_handle = CreateCompatibleBitmap(ps.hdc, width, height);

				size_t buffer_size_in_bytes = width * height * 3; // 3 color channels
				uint8_t* buffer = new uint8_t[buffer_size_in_bytes];

				int circle_center_y = 50;
				int circle_center_x = 75;
				float radius = 30.0f;

				for (int y = ps.rcPaint.top; y < ps.rcPaint.bottom; y++) {
					int y_difference = abs(circle_center_y - y);
					for (int x = ps.rcPaint.left; x < ps.rcPaint.right; x++) {
						int x_difference = abs(circle_center_x - x);
						float length_from_pixel_to_circle_center = sqrt((float)x_difference * x_difference + y_difference * y_difference);

						int i = ((y - ps.rcPaint.top) * width * 3) + ((x - ps.rcPaint.left) * 3);
						buffer[i] = 0; // blue
						buffer[i+1] = 0; // green
						if (length_from_pixel_to_circle_center - radius > 0.0f) {
							buffer[i+2] = 0; // red
						} else {
							buffer[i+2] = 0xff; // red
						}
					}
				}

				BITMAPINFO bmi = {0};
				bmi.bmiHeader.biSize = sizeof(bmi);
				bmi.bmiHeader.biWidth = width;
				bmi.bmiHeader.biHeight = height;
				bmi.bmiHeader.biPlanes = 1;
				bmi.bmiHeader.biBitCount = 24;
				bmi.bmiHeader.biCompression = BI_RGB;
				bmi.bmiHeader.biSizeImage = buffer_size_in_bytes;
				HDC memory_dc = CreateCompatibleDC(ps.hdc);
				SetDIBits(memory_dc, bitmap_handle, 0, height, buffer, (BITMAPINFO*)&bmi, DIB_RGB_COLORS);
				HGDIOBJ old_bitmap_handle = SelectObject(memory_dc, bitmap_handle);
				BitBlt(ps.hdc, ps.rcPaint.left, ps.rcPaint.top, width, height, memory_dc, 0, 0, SRCCOPY);
				SelectObject(ps.hdc, old_bitmap_handle);
				DeleteObject(bitmap_handle);
				DeleteObject(memory_dc);
				delete[] buffer;

				EndPaint(window_handle_, &ps);
			}
			return 0;
		}

		return maxGUI::Form::OnWindowMessage(message, wparam, lparam);
	}

};

int maxGUIEntryPoint(maxGUI::FormContainer&& form_container) noexcept {
	maxGUI::FormFactory<ControlGalleryForm> control_gallery_form_factory;
	if (!form_container.CreateForm(control_gallery_form_factory, 775, 350, "Control gallery")) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}