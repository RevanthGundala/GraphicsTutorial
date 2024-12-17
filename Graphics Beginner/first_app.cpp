#include "first_app.h"

namespace lve {
	void first_app::run() {
		while (!lve_window.shouldClose()) {
			glfwPollEvents();
		}
	}
}