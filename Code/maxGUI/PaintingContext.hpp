// Copyright 2026, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_PAINTINGCONTEXT_HPP
#define MAXGUI_PAINTINGCONTEXT_HPP


#include <expected>

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#endif

#include <max/Containers/Rectangle.hpp>

#include <maxGUI/FormConcept.hpp>
#include <maxGUI/Texture.hpp>


namespace maxGUI
{

	class PaintingContext
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit PaintingContext(HWND window_handle, PAINTSTRUCT paint_info, HDC window_device_context, HDC memory_device_context) noexcept;
#endif

		PaintingContext(PaintingContext&& rhs) noexcept;
		~PaintingContext() noexcept;

		PaintingContext& operator =(PaintingContext&& rhs) noexcept;

		max::Containers::Rectangle<int, int> GetDirtyRectangle() noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
		HWND window_handle_;
		PAINTSTRUCT paint_info_;
		HDC window_device_context_;
		HDC memory_device_context_;
#endif
	};

	enum class CreatePaintingContextError {
	};
	std::expected<PaintingContext, CreatePaintingContextError> CreatePaintingContext(FormConcept& form);

	void PaintTexture(PaintingContext& painting_context, Texture& texture, int x, int y) noexcept;

} // namespace maxGUI

#endif // #ifndef MAXGUI_PAINTINGCONTEXT_HPP