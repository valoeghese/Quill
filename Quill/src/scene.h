#pragma once

namespace quill {
	class Window; // inline header decl.

	class Scene {
	public:
		virtual void render(Window* window) = 0;
		virtual void tick(Window* window) = 0;
	};
}
