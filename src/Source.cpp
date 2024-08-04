#include <cstdio>
#include <iostream>
#include "Core.h"
#include "Window.h"


void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void framebuffer_resize_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    // printf("FB resized: %d\n", width * height);
}


int main() {
	Window* window = new Window(1366, 768, "learnOpenGL");
    Timer frameWaitSleep("Frame Limiter", 1000.0f / 75.0f /*FPS*/, true);

    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window->window, key_callback);
    glfwSetFramebufferSizeCallback(window->window, framebuffer_resize_callback);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);

    while (!glfwWindowShouldClose(window->window)) {
        frameWaitSleep.start();

        glClear(GL_COLOR_BUFFER_BIT);
        frameWaitSleep.sleep();
        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }
	delete window;
	return 0;
}
