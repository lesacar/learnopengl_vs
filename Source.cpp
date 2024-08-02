#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>


class Timer
{
public:
	Timer(const std::string& name, double a_desiredWait_ms);
	~Timer();
	void start();
	void sleep();
	void set_ms(double ms);
	double elapsed();

private:
	std::string name;
	double begin;
	double end;
	double desiredWait_ms;
	double sleepFor;
	double elapsed_ms;
};

double Timer::elapsed() {
	return elapsed_ms;
}

Timer::Timer(const std::string& name, double a_desiredWait_ms)
	: name(name), desiredWait_ms(a_desiredWait_ms)
{
	std::cout << "Instantiated Timer \"" << this->name << "\"" << std::endl;
}

Timer::~Timer()
{
	std::cout << "Removed Timer \"" << this->name << "\"" << std::endl;
}

void Timer::start() {
	begin = glfwGetTime();
}

void Timer::sleep() {
	end = glfwGetTime();
	elapsed_ms = end - begin;
	sleepFor = desiredWait_ms - elapsed_ms;
	if (sleepFor > desiredWait_ms)
	{
		sleepFor = desiredWait_ms;
	}
	if (sleepFor != std::clamp(sleepFor, 13.25, 13.4))
	{
		std::cout << "FrameTime spiked!" << std::endl;
		std::cout << "Expected " << desiredWait_ms <<
			"ms  got: " << sleepFor << "ms\n";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(sleepFor)));
}

void Timer::set_ms(double ms) {
	desiredWait_ms = ms;
}





int main() {
	Timer frameWaitSleep("Frame Limiter", 1000.0f / 75.0f);
	if (!glfwInit()) { std::cout << "GLFW couldn't start:" << std::endl; glfwTerminate(); return -1; }
	GLFWwindow* window = glfwCreateWindow(1280, 720, "learnOpenGL", nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		std::cout << "Couldn't create window" << std::endl;
		exit(-1);
	}
	glfwMakeContextCurrent(window);
	int version = gladLoadGL();
	if (version == 0) {
		printf("Failed to initialize OpenGL context\n");
		return -1;
	}
	glfwSwapInterval(0); // VSync: 1=on / 0=off
	while (!glfwWindowShouldClose(window))
	{
		frameWaitSleep.start();
		glClear(GL_COLOR_BUFFER_BIT);
		

		frameWaitSleep.sleep();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}