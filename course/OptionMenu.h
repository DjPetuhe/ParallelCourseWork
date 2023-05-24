#include <iostream>
#include <string>
#include "BFSVerificator.h"
#include "GraphHelper.h"
#include "ParallelBFS.h"
#include "FileWorker.h"
#include "SerialBFS.h"
#include "OwnTimer.h"
using namespace std;

#pragma once

class OptionMenu
{
	static void runTests();
	static void runRandom(int size, int start, int finish, int threads);
	static void runFile(string dir, int threads);
	static void generateToFile(string dir, int size, int start, int finish);
	static void matrixGenerationInput(int& size, int& start, int& finish);
	static void runBfs(int** graph, int size, int start, int finish, int threads, OwnTimer timer);
public:
	static void menu();
};

