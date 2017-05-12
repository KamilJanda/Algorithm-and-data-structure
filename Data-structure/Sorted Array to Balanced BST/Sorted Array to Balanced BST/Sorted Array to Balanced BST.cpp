// Sorted Array to Balanced BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;


struct BBSTNode
{
	BBSTNode *p, *left, *right;
	int key;

	BBSTNode(int x)
	{
		key = x;
		left = NULL;
		right = NULL;
	}
};

BBSTNode* makeBalancedBST(int arr[], int start,int end) //O(n)
{
	if (start<=end)
	{
		int mid = (start + end) / 2;

		BBSTNode* root = new BBSTNode(arr[mid]);

		root->left = makeBalancedBST(arr, start, mid - 1);
		root->right = makeBalancedBST(arr, mid + 1, end);

		return root;
	}
	else
	{
		return NULL;
	}
}

void inOrderTreeWalk(BBSTNode* root)
{
	if (root != NULL)
	{
		inOrderTreeWalk(root->left);
		cout << root->key << " ";
		inOrderTreeWalk(root->right);
	}
}

int main()
{
	int test[6] = { 2,3,4,5,7,9 };

	BBSTNode* tree = makeBalancedBST(test, 0, 5);

	inOrderTreeWalk(tree);

	system("pause");
    return 0;
}

