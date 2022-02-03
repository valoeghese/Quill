#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "quill.h"

using std::cout;
using std::endl;

using quill::Window;

int main() {
	if (!glfwInit()) {
		cout << "GLFW Failed to Initialise." << endl;
		return -1;
	}

	Window* window = quill::CreateWindow(500, 500, "Quill Lib Test");

	if (!window) {
		cout << "GL Failed to Initialise." << endl;
		return -1;
	}

	while (!window->ShouldClose()) {
		window->ClearBuffers();
		window->SwapBuffers();
	}

	delete window;
	return 0;
}
