#pragma once
#include <cstdint>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct GLFWvidmode;
struct GLFWmonitor;
struct GLFWwindow;

class Window
{
public:
	Window(uint32_t width, uint32_t height, std::string name);
	~Window();
public:
	GLFWwindow* window;
private:
	const GLFWvidmode* vidmode;
	GLFWmonitor* monitor;
	uint32_t width, height;
	std::string name;
	uint32_t gladVersion;
};
