#include <iomanip>
#include <iostream>
using namespace std;

#pragma once

class GraphHelper
{
private:
	static int* arrayShuffle(int graphSize, int s, int f);
public:
	static int** randomInicial(int graphSize, int s, int f);
	static void print(int** graph, int graphSize);
};
