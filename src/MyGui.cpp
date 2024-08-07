#include "backends/imgui_impl_glfw.h"
#include <MyGui.h>
#include <cstdio>
#include <cstdlib>

MyGui::MyGui() {
	fprintf(stderr, "Must provide arguments to MyGui::MyGui()\n");
	exit(-1);
}

MyGui::MyGui(GLFWwindow* window) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void MyGui::BeginFrame() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void MyGui::EndFrame() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

MyGui::~MyGui() {

}
