// Graph and its representations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct adjListNode
{
	int dest;
	adjListNode* next;

	adjListNode(int x)
	{
		next = NULL;
		dest = x;
	}
};

struct graph
{
	int V;
	adjListNode** array;

	graph(int size)
	{
		V = size;
		array = new adjListNode*[V];
		for (int i = 0; i < V; i++) array[i] = NULL;
	}
};

void addEdge(graph* G, int scr, int dest)
{
	adjListNode* item = new adjListNode(dest);

	item->next=G->array[scr];
	G->array[scr] = item;
}

void printList(graph* G)
{
	adjListNode* tmp;

	for (int i = 0; i < G->V; i++)
	{
		tmp = G->array[i];

		cout << "[" << i << "]";
		while (tmp != NULL)
		{
			cout << "->" << tmp->dest;
			tmp = tmp->next;
		}
		cout << endl;
	}
}


int main()
{
	graph* G = new graph(5);

	addEdge(G, 1, 2);
	addEdge(G, 1, 3);
	addEdge(G, 2, 5);
	addEdge(G, 4, 1);
	addEdge(G, 4, 2);
	addEdge(G, 5, 3);

	printList(G);

	system("pause");
    return 0;
}

