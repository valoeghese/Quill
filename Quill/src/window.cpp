#include "window.h"

#include <iostream>
#include <unordered_map>

namespace quill {
	// Const, Dest, static stuff
	std::unordered_map<GLFWwindow*, Window*> reverse_lookup;

	Window::Window(int width, int height, GLFWwindow* glfw_inst) {
		this->width = width;
		this->height = height;
		this->glfw_inst = glfw_inst;
		reverse_lookup[glfw_inst] = this;
		glfwSetFramebufferSizeCallback(this->glfw_inst, Window::OnWindowResize);
	}
	
	Window::~Window() {
		reverse_lookup.erase(this->glfw_inst); // remove the reference to this
		glfwDestroyWindow(this->glfw_inst);
	}

	void Window::OnWindowResize(GLFWwindow* window, int width, int height) {
		reverse_lookup[window]->OnResize(window, width, height);
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
	
	void Window::OnResize(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
		this->width = width;
		this->height = height;
	}

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