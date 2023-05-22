#include "OwnTimer.h"

OwnTimer::OwnTimer()
{
	this->start = steady_clock::now();
	this->end = steady_clock::now();
}

void OwnTimer::stopTimer()
{
	if (!stopped)
	{
		stopped = true;
		this->end = steady_clock::now();
	}
}

void OwnTimer::restartTimer()
{
	stopped = false;
	this->start = steady_clock::now();
	this->end = steady_clock::now();
}

double OwnTimer::getTime()
{
	if (stopped)
		return double(duration_cast<nanoseconds>(end - start).count()) / 1e9;
	return 0;
}

void OwnTimer::printTime(string str)
{
	if (stopped)
	{
		double duration = double(duration_cast<nanoseconds>(end - start).count()) / 1e9;
		cout << str << " time (sec) = " << duration << endl;
	}
}
