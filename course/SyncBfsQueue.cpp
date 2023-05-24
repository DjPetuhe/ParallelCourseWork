#include "SyncBfsQueue.h"

SyncBfsQueue::SyncBfsQueue(int numberOfNodes, int startNode)
{
	this->numberOfNodes = numberOfNodes;
	this->queues = vector<queue<int>>(1);
	this->inQueue = vector<bool>(numberOfNodes, false);
	this->levels = vector<int>(numberOfNodes, 0);
	queues[0].push(startNode);
	inQueue[startNode] = true;
	this->enqueued = 1;
}

bool SyncBfsQueue::tryAdd(int el, int parent)
{
	lock_guard<mutex> guard(mtx);
	if (enqueued == numberOfNodes || inQueue[el])
		return false;

	if (levels[parent] + 1 == queues.size())
		queues.push_back(queue<int>());

	int currLevel = levels[parent] + 1;
	queues[currLevel].push(el);
	levels[el] = currLevel;
	inQueue[el] = true;
	enqueued++;

	return true;
}

int SyncBfsQueue::pop()
{
	lock_guard<mutex> guard(mtx);
	for (int i = 0; i < queues.size(); i++)
	{
		if (!queues[i].empty())
		{
			int front = queues[i].front();
			queues[i].pop();
			return front;
		}
	}
	return -1;
}

bool SyncBfsQueue::allQueued()
{
	lock_guard<mutex> guard(mtx);
	return enqueued == numberOfNodes;
}
