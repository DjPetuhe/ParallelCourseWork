#include "OptionMenu.h"

void OptionMenu::runRandom(int size, int start, int finish, int threads)
{
	OwnTimer timer;
	int** graph = GraphHelper::randomInicial(size, start, finish);
	timer.stopTimer();
	timer.printTime("Matrix generation");

	runBfs(graph, size, start, finish, threads, timer);
}

void OptionMenu::runFile(string dir, int threads)
{
	OwnTimer timer;
	int size = 0, start = 0, finish = 0;
	int** graph = FileWorker::readGraph(dir, size, start, finish);
	timer.stopTimer();
	timer.printTime("Matrix reading");

	runBfs(graph, size, start, finish, threads, timer);
}

void OptionMenu::runBfs(int** graph, int size, int start, int finish, int threads, OwnTimer timer)
{
	timer.restartTimer();
	int* parents = SerialBFS::findPath(graph, size, start);
	timer.stopTimer();
	vector<int> path = GraphHelper::pathByParents(parents, start, finish);
	cout << "Serial algorithm:" << endl;
	GraphHelper::printPath(path);
	cout << "Serial algorithm path exist = " << boolalpha << BFSVerificator::verificate(graph, path, size) << endl;
	timer.printTime("Serial bfs");

	timer.restartTimer();
	int* parents2 = ParallelBFS::findPath(graph, size, start, threads);
	timer.stopTimer();
	vector<int> path2 = GraphHelper::pathByParents(parents2, start, finish);
	cout << "Parallel algorithm:" << endl;
	GraphHelper::printPath(path);
	cout << "Parallel algorithm path exist = " << boolalpha << BFSVerificator::verificate(graph, path2, size, path.size()) << endl;
	timer.printTime("Parallel bfs");

	for (int i = 0; i < size; i++)
		delete[] graph[i];
	delete graph;
}

void OptionMenu::generateToFile(string dir, int size, int start, int finish)
{
	int** graph = GraphHelper::randomInicial(size, start, finish);
	FileWorker::writeGraph(dir, graph, size, start, finish);
}

void OptionMenu::runTests()
{
	OwnTimer timer;
	const int START = 1;
	int threads[5] = { 2, 4, 6, 8, 10 };
	int sizes[5] = { 1000, 2000, 5000, 10000, 20000 };
	bool allTrue = true;
	for (int i = 0; i < 5; i++)
	{
		int** graph = GraphHelper::randomInicial(sizes[i], START, sizes[i]);
		double serialTime = 0;
		for (int j = 0; j < 5; j++)
		{
			timer.restartTimer();
			int* parents = SerialBFS::findPath(graph, sizes[i], START);
			timer.stopTimer();
			allTrue &= BFSVerificator::verificate(graph, GraphHelper::pathByParents(parents, START, sizes[i]), sizes[i]);
			serialTime += timer.getTime();
		}
		cout << "Serial algorithm average time [size=" << sizes[i] << "]: " << serialTime / 5 << endl;
		for (int j = 0; j < 5; j++)
		{
			double parallelTime = 0;
			for (int k = 0; k < 5; k++)
			{
				timer.restartTimer();
				int* parents = ParallelBFS::findPath(graph, sizes[i], START, threads[j]);
				timer.stopTimer();
				allTrue &= BFSVerificator::verificate(graph, GraphHelper::pathByParents(parents, START, sizes[i]), sizes[i]);
				parallelTime += timer.getTime();
			}
			cout << "Parallel algorithm average time [size=" << sizes[i] << ", threads=" << threads[j] << "]: " << parallelTime / 5 << endl;
		}
		cout << endl;

		for (int i = 0; i < sizes[i]; i++)
			delete[] graph[i];
		delete graph;
	}
	cout << "All tests were succesefull: " << boolalpha << allTrue << endl;
}

void OptionMenu::menu()
{
	int size, start, finish, threads;
	char option;
	string dir;
	cout << "(0) Run bfs with random matrix generation" << endl;
	cout << "(1) Run bfs with matrix read from file" << endl;
	cout << "(2) Generate random matrix and write to file" << endl;
	cout << "(3) Run tests" << endl;
	cout << "Choose option: ";
	cin >> option;
	switch (option)
	{
	case '0':
		system("cls");
		matrixGenerationInput(size, start, finish);
		cout << "Enter threads amount: ";
		cin >> threads;
		runRandom(size, start, finish, threads);
		break;
	case '1':
		system("cls");
		cout << "Enter directory to read from: ";
		cin >> dir;
		cout << "Enter threads amount: ";
		cin >> threads;
		runFile(dir, threads);
		break;
	case '2':
		system("cls");
		matrixGenerationInput(size, start, finish);
		cout << "Enter directory to write to: ";
		cin >> dir;
		generateToFile(dir, size, start, finish);
		break;
	case '3':
		system("cls");
		runTests();
		break;
	default:
		system("cls");
		cout << "Wrong input! try again!" << endl;
		menu();
		break;
	}
}

void OptionMenu::matrixGenerationInput(int& size, int& start, int& finish)
{
	cout << "Enter size of generating matrix: ";
	cin >> size;
	cout << "Enter start node: ";
	cin >> start;
	cout << "Enter finish node: ";
	cin >> finish;
}
