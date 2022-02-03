#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace quill {
	class Window {
	private:
		int width;
		int height;
		GLFWwindow* glfw_inst;
	public:
		// const, dest

		Window(int width, int height, GLFWwindow* glfw_inst);
		~Window();

		// status

		// Returns whether this window should close.
		int ShouldClose();
		
		// other

		// Clears the colour and depth buffers of this window.
		void ClearBuffers();

		// Swaps the buffers and Polls GLFW events on the window.
		void SwapBuffers();
	};
}
