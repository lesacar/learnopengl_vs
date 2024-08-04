#include <cstdio>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Core.h"


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
    Timer frameWaitSleep("Frame Limiter", 1000.0f / 75.0f, false);

    if (!glfwInit()) {
        std::cout << "GLFW couldn't start:" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    if (!monitor) {
        std::cout << "monitor was null" << std::endl;
        glfwTerminate();
        return -1;
    }

    const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
    if (!vidmode) {
        std::cout << "vidmode was null" << std::endl;
        glfwTerminate();
        return -1;
    }
    uint32_t width = 1366, height = 768;
    GLFWwindow* window = glfwCreateWindow(width, height, "learnOpenGL", NULL, NULL);

    if (!window) {
        glfwTerminate();
        std::cout << "Couldn't create window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
    int version = gladLoadGL();
    if (version == 0) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }
    // ALL INIT DONE
    glViewport(0, 0, width, height);
    printf("FrameBuffer size (pixels): %d\n", width * height);

    while (!glfwWindowShouldClose(window)) {
        frameWaitSleep.start();
        glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT);
        frameWaitSleep.sleep();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
