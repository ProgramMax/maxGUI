// Copyright 2026, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "Texture.hpp"


#include <utility>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

namespace maxGUI
{

#if defined(MAX_PLATFORM_WINDOWS)
	Texture::Texture(HBITMAP bitmap_handle, int width, int height) noexcept
		: bitmap_handle_(std::move(bitmap_handle))
		, width_(std::move(width))
		, height_(std::move(height))
	{}
#endif

	Texture::Texture(Texture&& rhs) noexcept
		: bitmap_handle_(std::move(rhs.bitmap_handle_))
		, width_(std::move(rhs.width_))
		, height_(std::move(rhs.height_))
	{
		rhs.bitmap_handle_ = NULL;
	}

	Texture::~Texture() noexcept {
		if (bitmap_handle_ != NULL) {
			auto result = DeleteObject(bitmap_handle_);
			if (result == 0) {
				// There was an error.
				// But 1.) we're in a destructor, and 2.) there isn't much we can do about it other than debug or signal.
			}
		}
	}

	Texture& Texture::operator =(Texture&& rhs) noexcept {
		bitmap_handle_ = std::move(rhs.bitmap_handle_);
		width_         = std::move(rhs.width_);
		height_        = std::move(rhs.height_);

		rhs.bitmap_handle_ = NULL;

		return *this;
	}

	std::expected<Texture, CreateTextureForFormError> CreateTextureForForm(FormConcept& form, int width, int height, std::span<uint8_t> image_data) {
		auto window_dc_handle = GetDC(form.window_handle_);
		if (window_dc_handle == NULL) {
			return std::unexpected(CreateTextureForFormError::CouldNotGetFormFormat);
		}

		auto bitmap_handle = CreateCompatibleBitmap(window_dc_handle, width, height);
		if (bitmap_handle == NULL) {
			ReleaseDC(form.window_handle_, window_dc_handle);
			return std::unexpected(CreateTextureForFormError::CouldNotCreateBacking);
		}

		BITMAPINFO bmi = {};
		bmi.bmiHeader.biSize        = sizeof(bmi.bmiHeader);
		bmi.bmiHeader.biWidth       = width;
		bmi.bmiHeader.biHeight        = -height; // negative = top-down rows
		bmi.bmiHeader.biPlanes      = 1;
		bmi.bmiHeader.biBitCount    = 32;
		bmi.bmiHeader.biCompression = BI_RGB;
		bmi.bmiHeader.biSizeImage   = static_cast<DWORD>(image_data.size_bytes());

		auto result = SetDIBits(window_dc_handle, bitmap_handle, 0, height, image_data.data(), &bmi, DIB_RGB_COLORS);
		if (result == 0) {
			DeleteObject(bitmap_handle);
			ReleaseDC(form.window_handle_, window_dc_handle);
			return std::unexpected(CreateTextureForFormError::CouldNotPopulateBacking);
		}
		if (result == ERROR_INVALID_PARAMETER) {
			// The docs say if an error happens the return value is zero. But also the return value is this??
		}

		auto texture = Texture(std::move(bitmap_handle), std::move(width), std::move(height));

		result = ReleaseDC(form.window_handle_, window_dc_handle);
		if (result == 0) {
			DeleteObject(bitmap_handle);
			return std::unexpected(CreateTextureForFormError::CouldNotCleanUp);
		}

		return texture;
	}

	void CreateTextureForDesktop(int /*width*/, int /*height*/, std::span<uint8_t> /*image_data*/) {
		auto desktop_hdc = GetDC(NULL);
		if (desktop_hdc == NULL) {
			return; // for now, to prevent an error below
		}

		auto result = ReleaseDC(NULL, desktop_hdc);
		if (result == 0) {
		}
	}

/*
	void Foo(int width, int height) {
		// WM_WINDOWPOSCHANGED while dragging / WM_MOVE when drag is complete
		// WM_DISPLAYCHANGE when the user changes a setting or a monitor is (un)plugged
		// WM_DPICHANGED when the halfway point crosses to a monitor with a different DPI

		auto monitor_handle = MonitorFromWindow(window_handle, MONITOR_DEFAULTTONEAREST);

		auto monitor_info = MONITORINFO{ sizeof(MONITORINFO) };
		if (GetMonitorInfo(monitor_handle, &monitor_info)) {
			monitor_info.rcMonitor;  // full screen rect, eg 0,0 to 1920,1080
			monitor_info.rcWork; // usable workspace (excluding the taskbar, for example)
			monitor_info.dwFlag & MONITORINFOF_PRIMARY;
		}

		auto monitor_info_ex = MONITORINFOEX{ sizeof(MONITORINFOEX); };
		if (GetMonitorInfo(monitor_handle, &monitor_info_ex)) {
			auto monitor_dc = CreateDC(TEXT("DISPLAY"), monitor_info_ex.szDevice, NULL, NULL);
			if (monitor_dc) {
				auto bits_per_pixel = GetDeviceCaps(monitor_dc, BITSPIXEL);
				auto planes = GetDeviceCaps(monitor_dc, PLANES);

				auto color_depth = planes * bits_per_pixel;
				DeleteDC(monitor_dc);
			}
		}



		auto desktop_hdc = GetDC(NULL);

		// This is funky. It is the scaling, not the real DPI.
		// 96 is 100%
		// 144 is 150%
		auto dpi = GetDpiForWindow(window_handle);

		//auto CreateCompatibleDC(HDC device_context);
		auto backing = CreateCompatibleBitmap(desktop_hdc, width, height);
		//HGDIOBJ SelectObject(HDC device_context, HGDIOBJ object);
		//BOOL BitBlt(HDC device_context, int x, int y, int width, int height, HDC source, int x1, int y1, DWORD rop);
		// Likely ROP: SRCCOPY
		//int ReleaseDC(HWND window_handle, HDC device_context);
		//BOOL DeleteObject(HGDIOBJ object);
		//BOOL DeleteDC(HDC device_context);

		/*
		const HWND desktop_window_handle = NULL;
		auto desktop_device_context = GetDC(desktop_window_handle);
		if (desktop_device_context == NULL) {
			// GetLastError()
		}
		auto foo = CreateCompatibleDC(desktop_device_context);


		auto texture_bitmap = CreateCompatibleBitmap(desktop_device_context, width, height);
		auto result = ReleaseDC(desktop_window_handle, desktop_device_context);
		if (result == 0) {
			// error
		}
		auto old_bitmap = SelectObject(foo, texture_bitmap);
		auto result = DeleteObject(old_bitmap);
		*/
	//}

} // namespace maxGUI