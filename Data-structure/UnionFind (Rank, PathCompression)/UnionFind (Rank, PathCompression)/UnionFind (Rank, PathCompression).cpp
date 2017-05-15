// UnionFind (Rank, PathCompression).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	int val;
	int rank;
	node* parent;
};

node* makeSet(int x)
{
	node* set = new node;
	set->parent = set;
	set->val = x;
}

node* findSet(node* x)
{
	if (x != x->parent)
		x->parent = findSet(x->parent);
	return x->parent;
}

node* unionSet(node* x,node* y)
{
	if (x->rank < y->rank)
	{
		x->parent = y;
	}
	else if(x->rank>y->rank)
	{
		y->parent = x;
	}
	else
	{
		x->rank++;
		y->parent = x;
	}
}

int main()
{


	system("pause");
    return 0;
}

