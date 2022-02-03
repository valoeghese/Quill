#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "scene.h"

namespace quill {
	class Window {
	private:
		int width;
		int height;
		GLFWwindow* glfw_inst;
		Scene* current_scene = NULL;
		int should_close = 0;

		// Returns whether this window should close.
		int ShouldClose();
	public:
		// Const, Dest

		Window(int width, int height, GLFWwindow* glfw_inst);
		~Window();

		///////////////////////////////////////////
		// Accessors, Mutators, Status Functions //
		///////////////////////////////////////////

		// Retrieves the width of the window.
		int GetWidth();

		// Retrieves the height of the window.
		int GetHeight();

		// Sets the current scene of the window.
		void SetScene(Scene* scene);

		////////////////////////
		// Functional Methods //
		////////////////////////

		// Tells the window to close next frame.
		void Close();

		// Starts the main loop
		void MainLoop();
	};
}
