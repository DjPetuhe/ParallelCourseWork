#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#pragma once

class SerialBFS
{
public:
	static vector<int> findPath(int** graph, int size, int s, int f);
	static vector<int> pathByParents(int* parent, int s, int f);
};