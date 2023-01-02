#pragma once
#include "globals.h"

enum StatusLevel {
    Info, Warning, Error
};
const std::string levelNames[3] = { "Info", "Warning", "Error" };

class Log {
private:
	StatusLevel status;

public:
	void setStatusLevel(enum StatusLevel level);

	void logMessage(std::string msg);

	void logVecLab(VecLab& input);

	void logVecLabSegment(VecLab& input, int start, int end);
};

