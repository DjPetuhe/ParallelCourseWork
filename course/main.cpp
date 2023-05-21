#include <iostream>
#include "GraphHelper.h"
#include "SerialBFS.h"
#include "ParallelBFS.h"
using namespace std;

int main()
{
	//srand(time(NULL));
	int size = 10000;
	int** graph = GraphHelper::randomInicial(size, 5, 10);
	//GraphHelper::print(graph, size);
	vector<int> path = SerialBFS::findPath(graph, size, 5, 10);
	for (int i = 0; i < path.size() - 1; i++)
		cout << path[i] + 1 << "->";
	cout << path[path.size() - 1] + 1 << endl;
	vector<int> path2 = ParallelBFS::findPath(graph, size, 5, 10, 8);
	for (int i = 0; i < path2.size() - 1; i++)
		cout << path2[i] + 1 << "->";
	cout << path2[path2.size() - 1] + 1;
	for (int i = 0; i < size; i++)
		delete[] graph[i];
	delete graph;
}
