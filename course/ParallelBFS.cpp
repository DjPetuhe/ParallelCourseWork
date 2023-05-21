#include "ParallelBFS.h"

vector<int> ParallelBFS::findPath(int** graph, int size, int s, int f, int threads)
{
	bool finished = false;
	int* parent = new int[size] { -1 };
	SyncBfsQueue plan(size);
	vector<thread> bfsThreads;

	plan.tryAdd(s - 1);
	for (int i = 0; i < threads; i++)
	{
		bfsThreads.push_back(thread([&parent, &plan, &graph, size, f, &finished]()
		{
			while (!plan.isEmpty() && !finished)
			{
				int curr = plan.pop();
				for (int i = 0; i < size; i++)
				{
					if (graph[curr][i] && plan.tryAdd(i))
					{
						parent[i] = curr;
						if (i == f - 1)
							finished = true;
					}
				}
			}
		}));
	}

	for (int i = 0; i < bfsThreads.size(); i++)
		bfsThreads[i].join();

	return pathByParents(parent, s, f);
}

vector<int> ParallelBFS::pathByParents(int* parent, int s, int f)
{
	vector<int> path;

	int curr = f - 1;
	path.push_back(f - 1);
	while (curr != s - 1)
	{
		curr = parent[curr];
		path.push_back(curr);
	}

	delete[] parent;

	reverse(path.begin(), path.end());
	return path;
}
