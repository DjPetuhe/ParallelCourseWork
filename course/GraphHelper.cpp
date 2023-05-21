#include "GraphHelper.h"

int* GraphHelper::arrayShuffle(int size, int s, int f)
{
	int* order = new int[size];

	for (int i = 0; i < size; i++)
		order[i] = i;

	for (int i = 0; i < size; i++)
	{
		int j = rand() % size;
		int k = order[i];
		order[i] = order[j];
		order[j] = k;
	}

	for (int i = 1; i < size - 1; i++)
	{
		if (order[i] == s - 1)
		{
			order[i] = order[0];
			order[0] = s - 1;
		}
		else if (order[i] == f - 1)
		{
			order[i] = order[size - 1];
			order[size - 1] = f - 1;
		}
	}

	return order;
}

int** GraphHelper::randomInicial(int size, int s, int f)
{
	int* order = arrayShuffle(size, s, f);
	int** graph = new int *[size];

	for (int i = 0; i < size; i++)
	{
		graph[i] = new int[size] { 0 };
	}

	for (int i = 0; i < size - 1; i++)
		graph[order[i]][order[i + 1]] = 1;

	delete[] order;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (graph[i][j] != 0 || i == j)
				continue;
			if ((i == f - 1) || (j == s - 1))
				continue;
			if (rand() % (size / 2) == 0)
				graph[i][j] = 1;
		}
	}

	return graph;
}

void GraphHelper::print(int** graph, int size)
{
	cout << endl << "    ";

	for (int i = 0; i < size; i++)
		cout << setw(3) << i + 1;
	cout << endl << "    ";

	for (int i = 0; i < size; i++)
		cout << "---";
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(2) << i + 1 << " |";
		for (int j = 0; j < size; j++)
			cout << setw(3) << graph[i][j];
		cout << endl;
	}
}

vector<int> GraphHelper::pathByParents(int* parent, int s, int f)
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
