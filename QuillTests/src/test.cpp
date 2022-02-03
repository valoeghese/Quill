#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "quill.h"

using std::cout;
using std::endl;

using quill::Window;
using quill::Scene;

class TestScene : public Scene {
	virtual void render(Window* window) {
		cout << window->GetWidth() << endl;
	}

	virtual void tick(Window* window) {

	}
};

int main() {
	
	if (!glfwInit()) {
		cout << "GLFW Failed to Initialise." << endl;
		return -1;
	}

	Window* window;

	try {
		window = quill::CreateWindow(500, 500, "Quill Lib Test");
	}
	catch (int err) {
		cout << "Error creating window. Error code " << err << endl;
		return -1;
	}

	Scene* test_scene = new TestScene;
	window->SetScene(test_scene);

	window->MainLoop();

	delete test_scene;
	delete window;
	return 0;
}
