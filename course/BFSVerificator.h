#include <vector>
using namespace std;

#pragma once

class BFSVerificator
{
public:
	static bool verificate(int** graph, vector<int> path, int size);
	static bool verificate(int** graph, vector<int> path, int size, int neededLength);
};

