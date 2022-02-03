#include <iostream>

//#define QUILL_GL_TESTING
#include "quill.h";

using std::cout;
using std::endl;

using quill::Window;

int main() {
#ifdef QUILL_GL_TESTING
	return quill::test();
#else
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
#endif
}
