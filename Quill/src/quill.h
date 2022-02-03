#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.h"

namespace quill {
	Window* CreateWindow(int width, int height, std::string title);
}
