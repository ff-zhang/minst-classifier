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
	std::string outStr = "";
	auto segmented = input.segment(0, 8);
	for (auto it = segmented.begin(); it != segmented.end(); it++)
	{
		outStr += std::to_string(*it) + ", ";
	}

	logMessage(std::format("[{:<10} ... {:.6f}]", outStr, input.tail(1)[0]));
}

void Log::logVecLabSegment(VecLab& input, int start, int end)
{
	std::string outStr = "";
	auto segmented = input.segment(start, end);
	for (auto it = segmented.begin(); it != segmented.end(); it++)
	{
		outStr += std::to_string(*it) + ", ";
	}

	logMessage(std::format("[...{}...]", outStr));
}

