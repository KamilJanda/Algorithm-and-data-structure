// EulerianPathCircuitUndirectedGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	int vertex;
	node* next=NULL;
};

int size(node* head)
{
	int sum = 0;
	while (head->next != NULL)
	{
		sum++;
		head = head->next;
	}
	return sum;
}

class Graph
{
	int V;
	node** adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void addEdgeUtil(int v, int w);
	bool isConnected();	
	void DFSUtil(int v, bool visited[]);
	int isEulerian();

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
}

void Graph::addEdge(int v, int w)
{
	addEdgeUtil(v, w);
	addEdgeUtil(w, v);
}

void Graph::addEdgeUtil(int v, int w)
{
	node* item = new node;
	item->vertex = w;

	item->next=adj[v]->next;
	adj[v]->next = item;
}

bool Graph::isConnected()
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) visited[i] = false;

	int i;  //vertex to start

	for (i = 0; i < V; i++)
	{
		if (adj[i]->next != NULL) break; //Find Vertex with no-zero degree
	}

	if (i == V) return true; //Graph has no edges

	DFSUtil(i, visited);

	// Check if all non-zero degree vertices are visited
	for (int i = 0; i < V; i++)
	{
		if (adj[i]->next != NULL&&visited[i] == false) return false;
	}

	return true;
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;

	node* adjacent = adj[v]->next;

	while (adjacent!=NULL)
	{
		if (visited[adjacent->vertex] == false) DFSUtil(adjacent->vertex,visited);

		adjacent = adjacent->next;
	}
}

int Graph::isEulerian()
{
	int odd = 0;
	if (isConnected() == false) return  0; //not Eulerian

	for (int i = 0; i < V; i++)
	{
		if (size(adj[i]) % 2 != 0) odd++;
	}

	if (odd > 2) return 0; //not Eulerian
	else if (odd == 2) return 1; //Euler path
	else if (odd == 0) return 2; //Euler circuit // Note that odd count can never be 1 for undirected graph
}



void test(Graph &G)
{
	int res = G.isEulerian();

	if (res == 0)
	{
		cout << "Not Eulerian"<<endl;
	}
	else if (res == 1)
	{
		cout << "Euler path"<<endl;
	}
	else cout << " Euler cycle"<<endl;
}

int main()
{
	// Let us create and test graphs shown in above figures
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	test(g1);

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.addEdge(4, 0);
	test(g2);

	Graph g3(5);
	g3.addEdge(1, 0);
	g3.addEdge(0, 2);
	g3.addEdge(2, 1);
	g3.addEdge(0, 3);
	g3.addEdge(3, 4);
	g3.addEdge(1, 3);
	test(g3);

	// Let us create a graph with 3 vertices
	// connected in the form of cycle
	Graph g4(3);
	g4.addEdge(0, 1);
	g4.addEdge(1, 2);
	g4.addEdge(2, 0);
	test(g4);

	// Let us create a graph with all veritces
	// with zero degree
	Graph g5(3);
	test(g5);


	system("pause");
    return 0;
}

