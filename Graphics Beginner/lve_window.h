#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>





namespace lve {
	class LveWindow {
	public: 
		LveWindow(int w, int h, std::string name) : width(w), height(h), windowName(name) {
			glfwInit();
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
			window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
		}
		~LveWindow() {
			glfwDestroyWindow(window);
			glfwTerminate();
		}
		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;

		bool shouldClose() {
			return glfwWindowShouldClose(window);
		}
	private:
		GLFWwindow* window;
		const int width;
		const int height;
		const std::string windowName;
	};
}