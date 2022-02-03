#include "window.h"

#include <iostream>

namespace quill {
	// Const, Dest

	Window::Window(int width, int height, GLFWwindow* glfw_inst) {
		this->width = width;
		this->height = height;
		this->glfw_inst = glfw_inst;
	}
	
	Window::~Window() {
		glfwDestroyWindow(this->glfw_inst);
	}

	// Info Methods
	
	int Window::ShouldClose() {
		return glfwWindowShouldClose(this->glfw_inst);
	}

	// Functional Methods

	void Window::ClearBuffers() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers(this->glfw_inst);
		glfwPollEvents();
	}
}