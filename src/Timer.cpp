#include "Timer.h"

#include <iostream>
#include <GLFW/glfw3.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include "VSync.h"

double Timer::elapsed() {
	return elapsed_ms;
}

Timer::Timer(const std::string& name, double a_desiredWait_ms, bool vsync)
	: name(name), begin(0), end(0), desiredWait_ms(a_desiredWait_ms), sleepFor(0), elapsed_ms(0), vsyncObj(nullptr)
{
	vsyncObj = new VSync(vsync);
	if (vsyncObj == nullptr) { std::cout << "NULL error" << std::endl; }
	std::cout << "Instantiated Timer \"" << this->name << "\"" << std::endl;
}

Timer::~Timer()
{
	delete vsyncObj;
	std::cout << "Removed Timer \"" << this->name << "\"" << std::endl;
}

void Timer::start() {
	begin = glfwGetTime();
}

void Timer::sleep() {
	end = glfwGetTime();
	elapsed_ms = end - begin;
	sleepFor = desiredWait_ms - elapsed_ms;
	if (sleepFor != std::clamp(sleepFor, 0.0, desiredWait_ms))
	{
		sleepFor = desiredWait_ms;
	}
	if (sleepFor != std::clamp(sleepFor, 13.25, 13.4))
	{
		std::cout << "FrameTime spiked!" << std::endl;
		std::cout << "Expected " << desiredWait_ms <<
			"ms  got: " << sleepFor << "ms\n";
	}
	if (!vsyncObj->get())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(sleepFor)));
	}
	
}

void Timer::set_ms(double ms) {
	desiredWait_ms = ms;
}
