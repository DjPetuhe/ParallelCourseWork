#include "SerialBFS.h"
#include <iostream>

vector<int> SerialBFS::findPath(int** graph, int size, int s, int f)
{
	bool finished = false;
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
	return pathByParents(parent, s, f);
}

vector<int> SerialBFS::pathByParents(int* parent, int s, int f)
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
