// Copyright 2026, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "PaintingContext.hpp"


#include <utility>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	PaintingContext::PaintingContext(HWND window_handle, PAINTSTRUCT paint_info, HDC window_device_context, HDC memory_device_context) noexcept
		: window_handle_(        std::move(window_handle))
		, paint_info_(           std::move(paint_info))
		, window_device_context_(std::move(window_device_context))
		, memory_device_context_(std::move(memory_device_context))
	{}
#endif

	PaintingContext::PaintingContext(PaintingContext&& rhs) noexcept
		: window_handle_(        std::move(rhs.window_handle_))
		, paint_info_(           std::move(rhs.paint_info_))
		, window_device_context_(std::move(rhs.window_device_context_))
		, memory_device_context_(std::move(rhs.memory_device_context_))
	{
		rhs.window_handle_         = NULL;
		rhs.window_device_context_ = NULL;
		rhs.memory_device_context_ = NULL;
	}

	PaintingContext::~PaintingContext() noexcept {
		if (memory_device_context_ != NULL) {
			auto result = DeleteDC(memory_device_context_);
			if (result == 0) {
				// There was an error.
				// But 1.) we're in a destructor, and 2.) there isn't much we can do about it other than debug or signal.
			}
		}
		if (window_handle_ != NULL) {
			EndPaint(window_handle_, &paint_info_);
		}
	}

	PaintingContext& PaintingContext::operator =(PaintingContext&& rhs) noexcept {
		window_handle_         = std::move(rhs.window_handle_);
		paint_info_            = std::move(rhs.paint_info_);
		window_device_context_ = std::move(rhs.window_device_context_);
		memory_device_context_ = std::move(rhs.memory_device_context_);

		rhs.window_handle_         = NULL;
		rhs.window_device_context_ = NULL;
		rhs.memory_device_context_ = NULL;

		return *this;
	}

	max::Containers::Rectangle<int, int> PaintingContext::GetDirtyRectangle() noexcept {
		return max::Containers::MakeRectangle<int, int>(paint_info_.rcPaint.left, paint_info_.rcPaint.top, paint_info_.rcPaint.right - paint_info_.rcPaint.left, paint_info_.rcPaint.bottom - paint_info_.rcPaint.top);
	}

	std::expected<PaintingContext, CreatePaintingContextError> CreatePaintingContext(FormConcept& form) {
		PAINTSTRUCT paint_info;
		auto window_device_context = BeginPaint(form.window_handle_, &paint_info);

		auto memory_device_context = CreateCompatibleDC(window_device_context);

		return PaintingContext{form.window_handle_, std::move(paint_info), std::move(window_device_context), std::move(memory_device_context)};
	}

	void PaintTexture(PaintingContext& painting_context, Texture& texture, int x, int y) noexcept {
		auto old_bitmap = SelectObject(painting_context.memory_device_context_, texture.bitmap_handle_);

		BitBlt(painting_context.window_device_context_, x, y, texture.width_, texture.height_, painting_context.memory_device_context_, 0, 0, SRCCOPY);

		SelectObject(painting_context.memory_device_context_, old_bitmap);
	}

} // namespace maxGUI