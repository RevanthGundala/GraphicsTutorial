#pragma once
#include "lve_window.h"
#include "lve_device.h"
#include "lve_pipeline.h"


namespace lve {
	class first_app
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();
	private:
		LveWindow lve_window{WIDTH, HEIGHT, "Vulkan window" };
		LveDevice lve_device{ lve_window };
		lve_pipeline pipeline{ lve_device,  "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", 
			lve_pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
	};
}

