#include "Clock.h"

Clock::Clock()
{
	_start = system_clock::now();
}

timePoint Clock::start()
{
	_start = system_clock::now();
	return _start;
}

timePoint Clock::getStart()
{
	return _start;
}

seconds Clock::chkTime()
{
	_end = system_clock::now();
	duration<int> sec = duration_cast<seconds>(_start - _end);
	return sec;
}

seconds Clock::chkTime(timePoint start)
{
	_end = system_clock::now();
	seconds sec = duration_cast<seconds>(_start - _end);
	return sec;
}

