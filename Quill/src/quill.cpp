#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.h"
#include "quill.h"

namespace quill {
#ifdef QUILL_GL_TESTING
	int test() {
		if (!glfwInit()) {
			return -1;
		}

		std::cout << "GLFW Didn't Die!\n";

		GLFWwindow* window = glfwCreateWindow(500, 500, "Quill Linking Test", NULL, NULL);

		if (!window) {
			return -1;
		}

		std::cout << "Window Created Successfully!\n";

		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK) {
			return -1;
		}

		std::cout << "GLEW Didn't DIE!\n";

		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
		return 0;
	}
#else
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
#endif
}
