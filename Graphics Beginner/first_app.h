#pragma once
#include "lve_window.h"


namespace lve {
	class first_app
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
		first_app();
		~first_app();

		void run();
	private:
		LveWindow lve_window{WIDTH, HEIGHT, "Vulkan window" };
	};
}

