#pragma once

#include <GLFW/glfw3.h>;

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
		int ShouldClose();
		// other
		void ClearBuffers();
		void SwapBuffers();
	};
}
