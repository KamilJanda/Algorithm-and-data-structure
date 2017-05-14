// Find the number of islands (DFS).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

const int n=5;

void DFSUtil(int u, bool* visited, int adj[n][n])
{
	visited[u] = true;

	for (int i = 0; i < n; i++)
	{
		if (adj[u][i] == 1 && visited[i] == false) DFSUtil(i, visited, adj);
	}
}

int numberOfIsland(int adj[n][n])
{
	int countIsland = 0;
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			countIsland++;
			DFSUtil(i, visited, adj);
		}
	}

	return countIsland;
}

int main()
{
	int M[5][5] = { { 1, 0, 0, 0, 0 },
					{ 0, 0, 1, 0, 0 },
					{ 0, 1, 0, 0, 1 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 1, 0, 0 } };

	cout << numberOfIsland(M);



	system("pause");
    return 0;
}

