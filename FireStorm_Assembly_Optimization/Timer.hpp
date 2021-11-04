#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <cmath>

#include "InstrumentationSession.hpp"

class Timer
{
private:
	const char* name;
	std::chrono::time_point<std::chrono::steady_clock> startPoint;
	bool stop;
public:
	Timer(const char* name) : name(name), stop(false) {
		startPoint = std::chrono::high_resolution_clock::now();
	}

	void Stop() {
		auto endPoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(startPoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::milliseconds>(endPoint).time_since_epoch().count();

		//std::cout << name << ": " << (end - start) << "ms\n";
		Instrumentor::Get().WriteProfile({ name, start, end });

		stop = true;
	}

	~Timer() {
		if (!stop)
			Stop();

		delete[] name;
	}
};

