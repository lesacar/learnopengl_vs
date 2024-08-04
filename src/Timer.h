#pragma once
#include <string>

class VSync;

class Timer
{
public:
	Timer(const std::string& name, double a_desiredWait_ms, bool vsync);
	~Timer();
	void start();
	void sleep();
	void set_ms(double ms);
	double elapsed();

private:
	VSync* vsyncObj;
	std::string name;
	double begin;
	double end;
	double desiredWait_ms;
	double sleepFor;
	double elapsed_ms;
};