#include "Logger.h"
#include <iostream>
#include <format>

void Log::setStatusLevel(enum StatusLevel level)
{
	status = level;
}

void Log::logMessage(std::string msg)
{
	std::string formattedOutput = std::format("[{}]: {}", levelNames[status], msg);
	std::cout << formattedOutput << "\n";
}

void Log::logVecLab(VecLab& input)
{
	const int outputNumber = 8;
	std::string outStr = "";
	int index = 0;
	for (auto it = input.begin(); it != input.end() && index < outputNumber; it++)
	{
		outStr += std::to_string(*it) + ", ";
		index++;
	}
	logMessage(std::format("[{:<10} ... {:.6f}]", outStr, input.tail(1).array()[0]));
}

void Log::logVecLabSegment(VecLab& input, int start, int end)
{

}

