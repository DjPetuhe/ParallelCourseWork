#include <iostream>
#include "GraphHelper.h"
#include "SerialBFS.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int size = 10000;
	int** graph = GraphHelper::randomInicial(size, 5, 10);
	//GraphHelper::print(graph, size);
	vector<int> path = SerialBFS::findPath(graph, size, 5, 10);
	for (int i = 0; i < path.size() - 1; i++)
		cout << path[i] + 1 << "->";
	cout << path[path.size() - 1] + 1;
	for (int i = 0; i < size; i++)
		delete[] graph[i];
	delete graph;
}
