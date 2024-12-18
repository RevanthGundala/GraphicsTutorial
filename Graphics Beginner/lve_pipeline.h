#pragma once
#include <string>
#include <vector>

#include "lve_device.h"

namespace lve {
	struct PipelineConfigInfo {};
	class lve_pipeline
	{
	public:
		lve_pipeline(LveDevice& device, const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
		~lve_pipeline();
		lve_pipeline(const lve_pipeline&) = delete;
		void operator=(const lve_pipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
			PipelineConfigInfo config;
			// Configure 'config' here if necessary
			return config;
		}

	private:
		static std::vector<char> readFile(const std::string& filename);
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
		LveDevice& device; // Potentially memory leak
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}

