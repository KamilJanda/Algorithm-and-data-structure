// Topological Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	int vertex;
	char colour;
	node* next = NULL;
};

class Graph
{
	int V;
	node** adj;
	int* result;
	int idResult;
public:
	Graph(int V);
	void addEdge(int w, int v);
	void topologicalSortUtil(int u);
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new node*[V];
	for (int i = 0; i < V; i++)
	{
		adj[i] = new node;
		adj[i]->vertex = i;
	}
	idResult = V - 1;
	result = new int[V];
}

void Graph::addEdge(int w, int v)
{
	node* item = new node;
	item->vertex = v;

	item->next = adj[w]->next;
	adj[w]->next = item;
}

void Graph::topologicalSortUtil(int u)
{
	adj[u]->colour = 'G';

	node* adjacentsU = adj[u]->next;

	while (adjacentsU!=NULL)
	{
		int v = adjacentsU->vertex; //id (vertex) in adjacent array
		if (adj[v]->colour == 'W') topologicalSortUtil(v);
		else if (adj[v]->colour == 'G')
		{
			cout << "It is not DAG";
			return;
		}

		adjacentsU = adjacentsU->next;
	}

	adj[u]->colour = 'B';
	result[idResult] = adj[u]->vertex;
	idResult--;
}

void Graph::topologicalSort() //O(V+E)
{
	for (int i = 0; i < V; i++)
	{
		adj[i]->colour = 'W';
	}

	for (int i = 0; i < V; i++)
	{
		if (adj[i]->colour == 'W') topologicalSortUtil(i);
	}

	for (int i = 0; i < V; i++) cout << result[i] << " ";

}


int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given graph \n";
	g.topologicalSort();

	system("pause");
    return 0;
}

