#include <iostream>
#include "GraphHelper.h"
#include "SerialBFS.h"
#include "ParallelBFS.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int size = 2000;
	int** graph = GraphHelper::randomInicial(size, 5, 10);
	//GraphHelper::print(graph, size);
	auto start = chrono::steady_clock::now();
	int* parents = SerialBFS::findPath(graph, size, 5);
	auto stop = chrono::steady_clock::now();
	vector<int> path = GraphHelper::pathByParents(parents, 5, 10);
	auto duration = double(chrono::duration_cast<chrono::nanoseconds>(stop - start).count());
	std::cout << "Time difference (sec) = " << duration / 1e9 << std::endl;
	for (int i = 0; i < path.size() - 1; i++)
		cout << path[i] + 1 << "->";
	cout << path[path.size() - 1] + 1 << endl;

	start = chrono::steady_clock::now();
	int* parents2 = ParallelBFS::findPath(graph, size, 5, 8);
	stop = chrono::steady_clock::now();
	vector<int> path2 = GraphHelper::pathByParents(parents2, 5, 10);
	duration = double(chrono::duration_cast<chrono::nanoseconds>(stop - start).count());
	std::cout << "Time difference (sec) = " << duration / 1e9 << std::endl;
	for (int i = 0; i < path2.size() - 1; i++)
		cout << path2[i] + 1 << "->";
	cout << path2[path2.size() - 1] + 1;
	for (int i = 0; i < size; i++)
		delete[] graph[i];
	delete graph;
}
