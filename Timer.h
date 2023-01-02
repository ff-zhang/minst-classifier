#pragma once

#include <chrono>
#include <string>

// This class records the time it takes to run a certain scope.
// Instantiate the timer inside of the intended scope, and it will automatically report the time upon destruction.
class ScopedTimer
{
private:
	std::string name;
	std::chrono::high_resolution_clock clock;
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

public:
	ScopedTimer(std::string timerName);

	~ScopedTimer();
};
