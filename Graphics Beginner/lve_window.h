#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>

namespace lve {
    class LveWindow {
    public:
        LveWindow(int w, int h, std::string name);
        ~LveWindow();
        LveWindow(const LveWindow&) = delete;
        LveWindow& operator=(const LveWindow&) = delete;

        bool shouldClose() {
            return glfwWindowShouldClose(window);
        }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
			if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
				throw std::runtime_error("failed to create window surface!");
			}
		}
    private:
        GLFWwindow* window;
        const int width;
        const int height;
        const std::string windowName;
    };
}
