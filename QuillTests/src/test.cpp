#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define QUILL_TESTING
#include "quill.h";

int main() {
#ifdef QUILL_TESTING
	return quill::test();
#else

#endif
}
