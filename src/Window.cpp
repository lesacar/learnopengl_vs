#include "Window.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>

Window::Window(uint32_t width, uint32_t height, std::string name)
	: window(nullptr), vidmode(nullptr), monitor(nullptr), width(width), height(height), name(name), gladVersion(0)
{
	if (!glfwInit()) {
        std::cout << "GLFW couldn't start:" << std::endl;
        glfwTerminate();
		exit(-1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	monitor = glfwGetPrimaryMonitor();
	if (!monitor) {
		std::cout << "monitor was null" << std::endl;
		exit(-1);
	}
	vidmode = glfwGetVideoMode(monitor);
	if (!vidmode) {
		std::cout << "vidmode was null" << std::endl;
		exit(-1);
	}
	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	if (!window) {
		glfwTerminate();
		std::cout << "Couldn't create window" << std::endl;
		exit(-1);
	}
	glfwMakeContextCurrent(window);
	printf("Instantiated window %s\n", name.c_str());
	gladVersion = gladLoadGL();
	if (gladVersion == 0) {
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		exit(-1);
	}
	printf("Loaded OpenGL: %s\n", glGetString(GL_VERSION));
	
	glViewport(0, 0, width, height);

	printf("FrameBuffer size (pixels): %d\n", width * height);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
}

Window::~Window()
{
	glfwDestroyWindow(window);
    glfwTerminate();
}
