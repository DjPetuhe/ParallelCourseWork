#include <mutex>
#include <vector>
#include <queue>
using namespace std;

#pragma once

class SyncBfsQueue
{
private:
	mutex mtx;
	vector<queue<int>> queues;
	vector<bool> inQueue;
	vector<int> levels;
	int enqueued;
	int numberOfNodes;
public:
	SyncBfsQueue(int numberOfNodes, int startNode);
	bool tryAdd(int el, int parent);
	int pop();
	bool allQueued();
};
