// K-LargestValueInBSTNoModification.cpp : Defines the entry point for the console application.
//K’th Largest Element in BST when modification to BST is not allowed

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct BSTNode
{
	int key;
	BSTNode* parent, *left, *right;
	BSTNode(int key)
	{
		this->key = key;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

//use to faster create BST
BSTNode* arrayToBST(int arr[], int from,int to)
{
	if (from <= to)
	{
		int mid = (from + to) / 2;
		BSTNode* root = new BSTNode(arr[mid]);

		root->left = arrayToBST(arr, from, mid - 1);
		if (root->left != NULL) root->left->parent = root;
		root->right = arrayToBST(arr, mid + 1, to);
		if (root->right != NULL) root->right->parent = root;

		return root;
	}
	else
	{
		return NULL;
	}
}

void reversInOrder(BSTNode* root, int &i,const int k,int &result)
{
	if (root != NULL)
	{
		reversInOrder(root->right,i,k,result);
		i++;
		if (i == k) 
		{
			result=root->key;
		}
		reversInOrder(root->left, i,k,result);
	}
}

void findKLargest(BSTNode* root,const int k)
{
	int i = 0;
	int res;
	reversInOrder(root, i, k,res);
	cout << "K-largest value: " << res;
}

int main()
{
	const int n = 7;
	int test[n] = { 4,8,10,12,14,20,22 };

	BSTNode* tree = arrayToBST(test, 0, n - 1);

	findKLargest(tree, 3);

	system("pause");
    return 0;
}

