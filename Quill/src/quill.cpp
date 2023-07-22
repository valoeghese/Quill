#include "quill.h"

namespace quill {
	Window* CreateWindow(int width, int height, std::string title) {
		GLFWwindow* glfwInst = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

		if (!glfwInst) {
			throw kNullWindowException;
		}
		
		Window* result = new Window(width, height, glfwInst);
		result->MakeContextCurrent();

		if (glewInit() != GLEW_OK) {
			delete result;
			throw kGlInitFailedException;
		}

		return result;
	}
}
