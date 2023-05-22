#include <mutex>
#include <vector>
using namespace std;

#pragma once

class SyncBfsQueue
{
private:
	mutex mtx;
	vector<int> queue;
	vector<bool> inQueue;
	int size;
	int realSize;
	int head;
	int tail;
public:
	SyncBfsQueue(int maxSize);
	bool tryAdd(int el);
	int pop();
	bool isEmpty();
};
