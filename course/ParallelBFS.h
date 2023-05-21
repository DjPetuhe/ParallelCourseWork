#include <vector>
#include "SyncBfsQueue.h"
using namespace std;

#pragma once

class ParallelBFS
{
public:
	static vector<int> findPath(int** graph, int size, int s, int f, int threads);
	static vector<int> pathByParents(int* parent, int s, int f);
};
