// DFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	int vertex;
	int timeIn;
	int timeOut;
	int parent;
	char colour; //black,grey,white
	node* next = NULL;
};

class Graph
{
public:
	int V;
	int time;
	node** adj;

	Graph(int V);
	void addEdge(int w, int v);
	void addEdgeUtil(int w, int v);
	void DFS();
	void DFSVisiting(int u);
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

void Graph::addEdge(int w, int v)
{
	addEdgeUtil(w, v);
	//addEdgeUtil(v, w);
}

void Graph::addEdgeUtil(int w, int v)
{
	node* item = new node;
	item->vertex = v;

	item->next = adj[w]->next;
	adj[w]->next = item;
}

void Graph::DFS()
{
	for (int i = 0; i < V; i++)
	{
		adj[i]->parent = -1;
		adj[i]->colour = 'W';
	}

	time = 0;

	for (int i = 0; i < V; i++)
	{
		if (adj[i]->colour == 'W') DFSVisiting(i);
	}
}

void Graph::DFSVisiting(int u) //O(V E)
{
	time++;
	adj[u]->timeIn = time;
	adj[u]->colour = 'G';

	node* tmp = adj[u]->next;

	while (tmp!=NULL)
	{
		if (adj[tmp->vertex]->colour == 'W')
		{
			adj[tmp->vertex]->parent = u;
			DFSVisiting(tmp->vertex);
		}
		tmp = tmp->next;
	}

	adj[u]->colour = 'B';
	time++;
	adj[u]->timeOut = time;
}


int main()
{
	Graph G(4);

	G.addEdge(0,3);	
	G.addEdge(0,1);
	G.addEdge(1,2);	
	G.addEdge(2,3);
	G.addEdge(3,1);	
	
	
	G.DFS();

	cout<<"time in 3: "<<G.adj[3]->timeIn<<endl;
	cout<<"time out 3: "<<G.adj[3]->timeOut;

	system("pause");
    return 0;
}

