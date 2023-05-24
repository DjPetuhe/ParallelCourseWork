#include "BFSVerificator.h"

bool BFSVerificator::verificate(int** graph, vector<int> path, int size)
{
    if (path.size() == 0)
        return false;
    for (int i = 0; i < path.size() - 1; i++)
    {
        int curr = path[0];
        int next = path[1];
        if (!graph[curr][next])
            return false;
    }
    return true;
}

bool BFSVerificator::verificate(int** graph, vector<int> path, int size, int neededLength)
{
    if (!verificate(graph, path, size))
        return false;
    return path.size() == neededLength;
}
