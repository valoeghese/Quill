#pragma once

#include <string>

#include "window.h"

namespace quill {
	// Indicates that the window created was null internally.
	const int kNullWindowException = 420;
	// Indicates that initialisation of OpenGL failed.
	const int kGlInitFailedException = 421;

	// Creates a window of the given width, height, and title, and initialises an OpenGL context in it.
	// The OpenGL context of the created window will be current after a successful call.
	// Throws: kNullWindowException if GLFWwindow constructed is null, or kGlInitFailedException if Quill could not initialise OpenGL.
	// Example: quill::Window* window = quill::CreateWindow(400, 400, "My Quill Window");
	Window* CreateWindow(int width, int height, std::string title);
}
