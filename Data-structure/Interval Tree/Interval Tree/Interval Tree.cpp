// Interval Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct interval
{
	int low;
	int high;
};

struct ITNode
{
	ITNode* parent, *left, *right;
	int key;
	char colour;
	interval inter;
	int max;
};

void intervalInsert()
{

}

void intervalDelete()
{

}

ITNode* search(ITNode* root,interval find) //O(lg(n))
{
	ITNode* tmp = root;

	while (tmp!=NULL&&((find.low<=tmp->inter.high&&tmp->inter.low<=find.high)==false))
	{
		if (tmp->left != NULL&&find.low <= tmp->left->max) tmp = tmp->left;
		else tmp = tmp->right;
	}
	return tmp;
}

int main()
{

	system("pause");
    return 0;
}

