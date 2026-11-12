// Copyright 2026, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MAXGUI_TEXTURE_HPP
#define MAXGUI_TEXTURE_HPP


#include <expected>
#include <span>

#include <max/Compiling/Configuration.hpp>

#if defined(MAX_PLATFORM_WINDOWS)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif

	#include <Windows.h>
#endif

#include <maxGUI/Control.hpp>
#include <maxGUI/FormConcept.hpp>


namespace maxGUI
{

	class Texture
	{
	public:

#if defined(MAX_PLATFORM_WINDOWS)
		explicit Texture(HBITMAP bitmap_handle, int width, int height) noexcept;
#endif

		Texture(Texture&& rhs) noexcept;
		~Texture() noexcept;

		Texture& operator =(Texture&& rhs) noexcept;

#if defined(MAX_PLATFORM_WINDOWS)
		HBITMAP bitmap_handle_;
		int width_;
		int height_;
#endif
	};

	enum class CreateTextureForFormError {
		CouldNotGetFormFormat,
		CouldNotCreateBacking,
		CouldNotPopulateBacking,
		CouldNotCleanUp,
	};
	std::expected<Texture, CreateTextureForFormError> CreateTextureForForm(FormConcept& form, int width, int height, std::span<uint8_t> image_data);

} // namespace maxGUI

#endif // #ifndef MAXGUI_TEXTURE_HPP