#pragma once
#include <chrono>
using namespace std::chrono;
using timePoint = system_clock::time_point;
class Clock
{
public:
	Clock();
	timePoint start();
	timePoint getStart();
	seconds chkTime();
	seconds chkTime(timePoint start);
private:
	timePoint _start;
	timePoint _end;
};

