#include "SerialBFS.h"

int* SerialBFS::findPath(int** graph, int size, int s)
{
	int* parent = new int[size] { -1 };
	bool* inQueue = new bool[size] { false };
	queue<int> plan;

	plan.push(s - 1);
	inQueue[s - 1] = true;
	while (!plan.empty())
	{
		int curr = plan.front();
		plan.pop();
		for (int i = 0; i < size; i++)
		{
			if (graph[curr][i] && !inQueue[i])
			{
				plan.push(i);
				inQueue[i] = true;
				parent[i] = curr;
			}
		}
	}

	delete[] inQueue;

	return parent;
}
