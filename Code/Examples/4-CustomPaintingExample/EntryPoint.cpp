// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <maxGUI/EntryPoint.hpp>
#include <maxGUI/Form.hpp>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#include <memory>

class CustomPaintingForm {
public:

	// An escape hatch is provided so a user is not limited by the library.
	// A user can implement whatever custom behavior they desire by interacting directly with the underlying API.
	// Here, we override the window's message handler in Win32 to impelement custom painting.
	LRESULT OnWindowMessage(maxGUI::FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
		switch (message) {
		case WM_ERASEBKGND:
			return 1; // defer erasing to WM_PAINT
		case WM_PAINT:
			{
				PAINTSTRUCT paint_info;
				HDC device_context = BeginPaint(form->window_handle_, &paint_info);
				
				int width = paint_info.rcPaint.right - paint_info.rcPaint.left;
				int height = paint_info.rcPaint.bottom - paint_info.rcPaint.top;

				HBITMAP bitmap_handle = CreateCompatibleBitmap(device_context, width, height);
				DWORD buffer_size_in_bytes = static_cast<size_t>(width) * height * 4; // 3 color channels, 4th channel is unused
				auto buffer = std::make_unique<uint8_t[]>(static_cast<size_t>(buffer_size_in_bytes));


				// Create a black background with a white circle in it
				int circle_center_y = 50;
				int circle_center_x = 75;
				double radius = 30.0;

				for (int y = paint_info.rcPaint.top; y < paint_info.rcPaint.bottom; y++) {
					int y_distance = abs(circle_center_y - y);

					for (int x = paint_info.rcPaint.left; x < paint_info.rcPaint.right; x++) {
						int x_distance = abs(circle_center_x - x);

						double distance_from_pixel_to_circle_center = sqrt(static_cast<double>(x_distance) * x_distance + static_cast<double>(y_distance) * y_distance);

						// Our paint rectangle might not be (0,0) top left.
						// For example, if the user resizes the window to reveal more, our paint rectangle might only be the newly revealed area.
						size_t buffer_y_offset = static_cast<size_t>(y) - paint_info.rcPaint.top;
						size_t buffer_x_offset = static_cast<size_t>(x) - paint_info.rcPaint.left;

						size_t i = ((buffer_y_offset * width) + buffer_x_offset) * 4;
						if (distance_from_pixel_to_circle_center < radius) {
							buffer[i+0] = 0xff; // blue channel
							buffer[i+1] = 0xff; // green channel
							buffer[i+2] = 0xff; // red channel
						} else {
							buffer[i+0] = 0; // blue channel
							buffer[i+1] = 0; // green channel
							buffer[i+2] = 0; // red channel

						}
						buffer[i+3] = 0; // unused channel
					}
				}


				BITMAPINFO bitmap_info = {{0}, {{0}}};
				bitmap_info.bmiHeader.biSize = sizeof(bitmap_info);
				bitmap_info.bmiHeader.biWidth = width;
				bitmap_info.bmiHeader.biHeight = -height;
				bitmap_info.bmiHeader.biPlanes = 1;
				bitmap_info.bmiHeader.biBitCount = 32;
				bitmap_info.bmiHeader.biCompression = BI_RGB;
				bitmap_info.bmiHeader.biSizeImage = buffer_size_in_bytes;
				HDC memory_dc = CreateCompatibleDC(device_context);
				SetDIBits(memory_dc, bitmap_handle, 0, static_cast<UINT>(height), buffer.get(), &bitmap_info, DIB_RGB_COLORS);
				HGDIOBJ old_bitmap_handle = SelectObject(memory_dc, bitmap_handle);
				BitBlt(device_context, paint_info.rcPaint.left, paint_info.rcPaint.top, width, height, memory_dc, 0, 0, SRCCOPY);
				SelectObject(device_context, old_bitmap_handle);
				DeleteObject(bitmap_handle);
				DeleteObject(memory_dc);

				EndPaint(form->window_handle_, &paint_info);
			}
			return 0;
		}

		return DefWindowProc(form->window_handle_, message, wparam, lparam);
	}

	void OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
		maxGUI::PostExitMessage(0);
	}

};

int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	maxGUI::FormFactory custom_painting_form_factory(maxGUI::GetDefaultFormAllocator<CustomPaintingForm>());
	if (!form_container.CreateForm(custom_painting_form_factory, 200, 350, "Custom painting")) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}