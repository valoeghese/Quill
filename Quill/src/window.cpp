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

	// Info/Accessor/Mutator Methods
	
	int Window::ShouldClose() {
		return this->should_close | glfwWindowShouldClose(this->glfw_inst);
	}

	int Window::GetWidth() {
		return this->width;
	}

	int Window::GetHeight() {
		return this->height;
	}

	void Window::SetScene(Scene* scene) {
		this->current_scene = scene;
	}

	// Functional Methods
	
	void Window::Close() {
		this->should_close = 1;
	}

	void Window::MainLoop() {
		while (!this->ShouldClose()) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			// render
			if (this->current_scene) {
				this->current_scene->render(this);
			}

			glfwSwapBuffers(this->glfw_inst);
			glfwPollEvents();
		}
	}
}