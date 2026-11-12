// Copyright 2020, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <optional>
#include <vector>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#include <maxGUI/maxGUI.hpp>

class CustomPaintingForm {
public:
	static const int texture_height = 100;
	static const int texture_width  = 100;

	// An escape hatch is provided so a user is not limited by the library.
	// A user can implement whatever custom behavior they desire by interacting directly with the underlying API.
	// Here, we override the window's message handler in Win32 to impelement custom painting.
	LRESULT OnWindowMessage(maxGUI::FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
		switch (message) {
		case WM_ERASEBKGND:
			return 1; // defer erasing to WM_PAINT
		case WM_PAINT:
			{
				auto painting_context = maxGUI::CreatePaintingContext(*form);
				if (!painting_context.has_value()) {
					return 0;
				}

				auto dirty_rectangle = painting_context->GetDirtyRectangle();

				if (black_texture_.has_value()) {
					auto dirty_rectangle_bottom = dirty_rectangle.TopLeft.Y() + dirty_rectangle.Height;
					for (int y = dirty_rectangle.TopLeft.Y(); y < dirty_rectangle_bottom; y += texture_height) {

						auto dirty_rectangle_right = dirty_rectangle.TopLeft.X() + dirty_rectangle.Width;
						for (int x = dirty_rectangle.TopLeft.X(); x < dirty_rectangle_right; x += texture_width) {
							maxGUI::PaintTexture(*painting_context, *black_texture_, x, y);
						}
					}
				}

				// We might overpaint the top-left but that's fine.
				if (dirty_rectangle.TopLeft.Y() < texture_height && dirty_rectangle.TopLeft.X() < texture_width) {
					if (circle_texture_.has_value()) {
						maxGUI::PaintTexture(*painting_context, *circle_texture_, 0, 0);
					}
				}
			}
			return 0;
		}

		return DefWindowProc(form->window_handle_, message, wparam, lparam);
	}


	void OnCreated(maxGUI::FormConcept* form) noexcept {
		const size_t buffer_size_in_bytes = texture_width * texture_height * 4; // 3 color channels, 4th channel is unused
		auto image_data = std::vector<uint8_t>(buffer_size_in_bytes);


		for (int y = texture_height - 1; y != 0; y--) {
			for (int x = texture_width - 1; x != 0; x--) {
				const size_t i = ((y * texture_width) + x) * 4; // 4 channels

				image_data[i+0] = 0; // blue
				image_data[i+1] = 0; // green
				image_data[i+2] = 0; // red
				image_data[i+3] = 0; // unused
			}
		}

		auto black_texture_creation_result = maxGUI::CreateTextureForForm(*form, texture_width, texture_height, std::span(image_data.data(), texture_height * texture_width));
		if (black_texture_creation_result.has_value()) {
			black_texture_ = *std::move(black_texture_creation_result);
		}


		const int circle_center_y = 50;
		const int circle_center_x = 70;
		const double radius = 30.0;

		for (int y = texture_height - 1; y != 0; y--) {
			const int y_distance = abs(circle_center_y - y);

			for (int x = texture_width - 1; x != 0; x--) {
				const int x_distance = abs(circle_center_x - x);
				const double distance_from_pixel_to_circle_center = sqrt(static_cast<double>(x_distance) * x_distance + static_cast<double>(y_distance) * y_distance);

				const size_t i = ((y * texture_width) + x) * 4; // 4 channels

				if (distance_from_pixel_to_circle_center < radius) {
					image_data[i+0] = 0xff; // blue
					image_data[i+1] = 0xff; // green
					image_data[i+2] = 0xff; // red
				} else {
					image_data[i+0] = 0; // blue
					image_data[i+1] = 0; // green
					image_data[i+2] = 0; // red
				}
				image_data[i+3] = 0; // unused
			}
		}

		auto circle_texture_creation_result = maxGUI::CreateTextureForForm(*form, texture_width, texture_height, std::span(image_data.data(), texture_height * texture_width));
		if (circle_texture_creation_result.has_value()) {
			circle_texture_ = *std::move(circle_texture_creation_result);
		}
	}


	void OnClosed(maxGUI::FormConcept* /*form*/) noexcept {
		maxGUI::PostExitMessage(0);
	}


	std::optional<maxGUI::Texture> black_texture_;
	std::optional<maxGUI::Texture> circle_texture_;
};


int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	auto form_allocator = maxGUI::GetDefaultFormAllocator<CustomPaintingForm>();
	if (!form_container.CreateForm<CustomPaintingForm>(350, 200, "Custom painting", form_allocator.get())) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}