// Copyright 2022, The maxGUI Contributors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <maxGUI/maxGUI.hpp>

// TODO: Provide platform-agnostic OpenGL wrappers for things like wglMakeCurrent(), etc.

class OpenGLForm {
public:

	void OnCreated(maxGUI::FormConcept* form) noexcept {
		device_context_ = GetDC(form->window_handle_);

		PIXELFORMATDESCRIPTOR pixel_format_descriptor;
		memset(&pixel_format_descriptor, 0, sizeof(pixel_format_descriptor));
		pixel_format_descriptor.nSize = sizeof(pixel_format_descriptor);
		pixel_format_descriptor.nVersion = 1;
		pixel_format_descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pixel_format_descriptor.iPixelType = PFD_TYPE_RGBA;
		pixel_format_descriptor.cColorBits = 32;
		pixel_format_descriptor.iLayerType = PFD_MAIN_PLANE;

		int pixel_format = ChoosePixelFormat(device_context_, &pixel_format_descriptor);
		SetPixelFormat(device_context_, pixel_format, &pixel_format_descriptor);
		DescribePixelFormat(device_context_, pixel_format, sizeof(PIXELFORMATDESCRIPTOR), &pixel_format_descriptor);

		rendering_context_ = wglCreateContext(device_context_);
		wglMakeCurrent(device_context_, rendering_context_);
	}

	void OnResized(maxGUI::FormConcept* form, int new_width, int new_height) noexcept {
		glViewport(0, 0, new_width, new_height);
		PostMessage(form->window_handle_, WM_PAINT, 0, 0);
	}

	void OnClosed(maxGUI::FormConcept* form) noexcept {
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(rendering_context_);
		ReleaseDC(form->window_handle_, device_context_);
		maxGUI::PostExitMessage(0);
	}

	LRESULT OnWindowMessage(maxGUI::FormConcept* form, UINT message, WPARAM wparam, LPARAM lparam) noexcept {
		switch (message) {

		case WM_KEYDOWN:
			switch (wparam) {
			case VK_ESCAPE:
				// TODO: Implement this
				//form->Close();
				break;
			}
			return 0;

		case WM_PAINT:
			{
				PAINTSTRUCT paint_info;
				BeginPaint(form->window_handle_, &paint_info);

				// This example uses old school immediate mode & the fixed function pipeline.
				// This method is VERY deprecated.
				// But it is also short, which makes it good for examples.
				glClear(GL_COLOR_BUFFER_BIT);
				glBegin(GL_TRIANGLES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex2i(0, 1);
				glColor3f(0.0f, 1.0f, 0.0f);
				glVertex2i(-1, -1);
				glColor3f(0.0f, 0.0f, 1.0f);
				glVertex2i(1, -1);
				glEnd();
				glFlush();
				SwapBuffers(device_context_);

				EndPaint(form->window_handle_, &paint_info);
			}
			return 0;
		}

		return DefWindowProc(form->window_handle_, message, wparam, lparam);
	}

private:

	HDC device_context_;
	HGLRC rendering_context_;

};

int maxGUIEntryPoint(maxGUI::FormContainer form_container) noexcept {
	maxGUI::FormFactory opengl_form_factory(maxGUI::GetDefaultFormAllocator<OpenGLForm>());
	if (!form_container.CreateForm(opengl_form_factory, 350, 200, "OpenGL")) {
		return -1;
	}

	return maxGUI::MessagePump(form_container);
}