#include "lve_pipeline.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace lve {
	lve_pipeline::lve_pipeline(LveDevice& device, const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo)
		: device(device), graphicsPipeline(VK_NULL_HANDLE), vertShaderModule(VK_NULL_HANDLE), fragShaderModule(VK_NULL_HANDLE)
	{
		createGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
	}
	lve_pipeline::~lve_pipeline() {
		vkDestroyShaderModule(device.device(), vertShaderModule, nullptr);
		vkDestroyShaderModule(device.device(), fragShaderModule, nullptr);
		vkDestroyPipeline(device.device(), graphicsPipeline, nullptr);
	}

	std::vector<char> lve_pipeline::readFile(const std::string& filename) {
		// binary read as binary instead of text
		// ate = when files open, go to end immediately (gets size of file)
		std::ifstream file(filename, std::ios::ate | std::ios::binary);
		if (!file.is_open()) {
			throw std::runtime_error("failed to open file: " + filename);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	void lve_pipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo) {
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

		std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n' << std::flush;
		std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n' << std::flush;

	}

	void lve_pipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(device.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("failed to create shader module!");
		}
	}
}