#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;

#pragma once

class OwnTimer
{
	steady_clock::time_point start;
	steady_clock::time_point end;
	bool stopped = false;
public:
	OwnTimer();
	void stopTimer();
	void restartTimer();
	double getTime();
	void printTime(string str);
};

