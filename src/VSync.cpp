#include "VSync.h"
#include <GLFW/glfw3.h>
#include <cstdio>
#include <iostream>

void VSync::set(bool vsync) {
    if (vsync)
    {
        std::cout << "VSync ON" << std::endl;
        glfwSwapInterval(1);

    }
    else
    {
        std::cout << "VSync OFF" << std::endl;

        glfwSwapInterval(0);
    }
    this->Vsync = vsync;
}

VSync::VSync(bool vsync)
    : Vsync(vsync)
{
    this->set(vsync);
}

bool VSync::get()
{
    return Vsync;
}
