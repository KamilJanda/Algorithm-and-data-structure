// BFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;

public:
	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::BFS(int s)
{
	bool* visited=new bool[V];
	for (int i = 0; i < V; i++) visited[i] = false;
	int currentV;

	list<int> queue;

	queue.push_back(s);
	visited[s] = true;

	list<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();
		cout << s <<" ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (visited[*i] == false)
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main()
{
	Graph G(8);

	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(2, 3);
	G.addEdge(1,4);
	G.addEdge(1,5);
	G.addEdge(4,7);
	G.addEdge(4,5);
	G.addEdge(5,6);
	G.addEdge(5,7);
	G.addEdge(6,7);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	G.BFS(0);


	system("pause");
    return 0;
}

