#pragma once
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

class MyGui {
public:
	MyGui();
	MyGui(GLFWwindow* window);
	void BeginFrame();
	void EndFrame();
	~MyGui();
private:
};
