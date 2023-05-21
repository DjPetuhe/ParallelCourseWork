#include "SyncBfsQueue.h"

SyncBfsQueue::SyncBfsQueue(int maxSize)
{
	this->head = 0;
	this->tail = 1;
	this->size = 0;
	this->realSize = maxSize;
	this->queue = vector<int>(maxSize);
	this->inQueue = vector<bool>(maxSize);
}

bool SyncBfsQueue::tryAdd(int el)
{
	lock_guard<mutex> guard(mtx);
	if (size == realSize || inQueue[el])
		return false;

	queue[tail - 1] = el;
	inQueue[el] = true;
	size++;

	if (tail == realSize - 1)
		tail = 1;
	else
		tail++;

	return true;
}

int SyncBfsQueue::pop()
{
	lock_guard<mutex> guard(mtx);
	if (size <= 0)
		return 0;

	int el = queue[head];
	size--;

	if (head == realSize - 1)
		head = 0;
	else
		head++;

	return el;
}

bool SyncBfsQueue::isEmpty()
{
	lock_guard<mutex> guard(mtx);
	return size == 0;
}
