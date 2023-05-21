#include <vector>
#include "SyncBfsQueue.h"
using namespace std;

#pragma once

class ParallelBFS
{
public:
	static int* findPath(int** graph, int size, int s, int threads);
};
