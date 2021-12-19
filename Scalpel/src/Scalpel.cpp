#include "Scalpel.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace scalpel {
	int test() {
		if (!glfwInit()) {
			return -1;
		}
		std::cout << "GLFW Didn't Die!\n";

		GLFWwindow* window = glfwCreateWindow(500, 500, "Scalpel Linking Test", NULL, NULL);

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
}
