#include "Scalpel.h"
#include <iostream>
#include <GLFW/glfw3.h>

namespace scalpel {
	int test() {
		if (!glfwInit()) {
			return -1;
		}
		std::cout << "Hello, World!\n";
		getchar();
		return 0;
	}
}
