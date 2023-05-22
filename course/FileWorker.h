#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#pragma once

class FileWorker
{
public:
	static int** readGraph(string dir, int &size, int &start, int &finish);
	static void writeGraph(string dir, int** graph, int size, int start, int finish);
};

