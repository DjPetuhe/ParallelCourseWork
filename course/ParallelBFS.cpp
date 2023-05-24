#include "ParallelBFS.h"

int* ParallelBFS::findPath(int** graph, int size, int s, int threads)
{
	int* parent = new int[size] { -1 };
	SyncBfsQueue plan(size, s - 1);
	vector<thread> bfsThreads;

	for (int i = 0; i < threads; i++)
	{
		bfsThreads.push_back(thread([&parent, &plan, &graph, size]()
		{
			while (!plan.allQueued())
			{
				int curr = plan.pop();
				if (curr == -1) continue;
				for (int i = 0; i < size; i++)
				{
					if (graph[curr][i] && plan.tryAdd(i, curr))
						parent[i] = curr;
				}
			}
		}));
	}

	for (int i = 0; i < bfsThreads.size(); i++)
		bfsThreads[i].join();

	return parent;
}