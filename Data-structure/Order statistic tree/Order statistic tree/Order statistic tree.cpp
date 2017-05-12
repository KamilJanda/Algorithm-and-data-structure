// Order statistic tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

using namespace std;

struct OSTreeNode
{
	OSTreeNode* parent, *left, *right;
	int key;
	int size;
	char colour;
};

int select(OSTreeNode* root, int i) //O(lg(n))
{
	int rank = root->left->size + 1;

	if (rank == i) return root->key;
	else if (i < rank) return select(root->left, i);
	return select(root->right, i - rank);
}

int rank(OSTreeNode* root, OSTreeNode* element) //O(lg(n))
{
	int rank;

	if (element->left != NULL) rank = element->left->size + 1;
	else rank = 1;

	while (element!=root)
	{
		if (element == element->parent->right)
		{
			element = element->parent;
			if (element->left != NULL) rank = element->left->size + 1 + rank;
			else rank++;
		}
		else element = element->parent;
	}

	return rank;
}

int main()
{
    return 0;
}

