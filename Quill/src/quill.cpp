#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.h"
#include "quill.h"

namespace quill {
	Window* CreateWindow(int width, int height, std::string title) {
		GLFWwindow* glfwInst = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		Window* result = new Window(width, height, glfwInst);

		glfwMakeContextCurrent(glfwInst);

		if (glewInit() != GLEW_OK) {
			delete result;
			return NULL;
		}

		return result;
	}
}
