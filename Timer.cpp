#include "Timer.h"
#include <chrono>
#include <iostream>

ScopedTimer::ScopedTimer(std::string timerName)
{
	name = timerName;
	clock = std::chrono::high_resolution_clock();
	startTime = clock.now();
}

ScopedTimer::~ScopedTimer()
{
	auto endTime = clock.now();
	int diff = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
	std::cout << name << " measured a time of " << diff << "ms.\n";
}