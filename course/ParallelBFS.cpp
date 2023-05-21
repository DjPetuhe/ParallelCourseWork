#include "ParallelBFS.h"
#include <chrono>

int* ParallelBFS::findPath(int** graph, int size, int s, int threads)
{
	int* parent = new int[size] { -1 };
	SyncBfsQueue plan(size);
	vector<thread> bfsThreads;

	plan.tryAdd(s - 1);
	for (int i = 0; i < threads; i++)
	{
		bfsThreads.push_back(thread([&parent, &plan, &graph, size]()
		{
			while (!plan.isEmpty())
			{
				int curr = plan.pop();
				for (int i = 0; i < size; i++)
				{
					if (graph[curr][i] && plan.tryAdd(i))
					{
						parent[i] = curr;
					}
				}
			}
		}));
	}

	for (int i = 0; i < bfsThreads.size(); i++)
		bfsThreads[i].join();

	return parent;
}