#include "FileWorker.h"

int** FileWorker::readGraph(string dir, int& size, int& start, int& finish)
{
	ifstream file(dir);
	file >> size >> start >> finish;

	int** graph = new int *[size];
	for (int i = 0; i < size; i++)
		graph[i] = new int[size] { 0 };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int check;
			file >> check;
			graph[i][j] = check;
		}
	}
	return graph;
}

void FileWorker::writeGraph(string dir, int** graph, int size, int start, int finish)
{
	ofstream file(dir);
	file << size << ' ' << start << ' ' << finish << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			file << graph[i][j] << ' ';
		}
		file << endl;
	}
}
