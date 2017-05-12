// Merge Two BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct BSTNode
{
	int key;
	BSTNode* p, *left, *right;

	BSTNode(int x)
	{
		key = x;
		left = NULL;
		right = NULL;
	}
};

int sizeOfTree(BSTNode* root)
{
	if (root == NULL)
		return 0;
	else return (sizeOfTree(root->left) + 1 + sizeOfTree(root->right));
}

void makeInOrderArr(BSTNode* root,int arr[],int* index_ptr) //O(n)
{
	if (root != NULL)
	{
		makeInOrderArr(root->left, arr, index_ptr);

		arr[(*index_ptr)] = root->key;
		(*index_ptr)++;

		makeInOrderArr(root->right, arr, index_ptr);
	}
}

int* mergeTwoArr(int* a,int sizeA, int* b,int sizeB) //O(n+m)
{
	int size = sizeA + sizeB;
	int idA = 0;
	int idB = 0;

	int* arr = new int[size];

	int i = 0;
	while(idA<sizeA&&idB<sizeB)
	{
		if (a[idA] > b[idB])
		{
			arr[i] = b[idB];
			idB++;
		}
		else
		{
			arr[i] = a[idA];
			idA++;
		}
		i++;
	}

	if (idA < sizeA)
	{
		arr[i] = a[idA];
		idA++;
		i++;
	}

	if (idB < sizeB)
	{
		arr[i] = a[idB];
		idB++;
		i++;
	}

	return arr;
}

BSTNode* sortedArrToBST(int arr[], int start, int end) //O(n)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;

		BSTNode* root = new BSTNode(arr[mid]);

		root->left = sortedArrToBST(arr, start, mid - 1);
		root->right = sortedArrToBST(arr, mid + 1, end);

		return root;
	}
	else
	{
		return NULL;
	}
}

BSTNode* mergeTwoBST(BSTNode* treeA, BSTNode* treeB) //O(n+m) n-sizeA m-sizeB
{
	int i;
	int sizeA = sizeOfTree(treeA);
	int sizeB = sizeOfTree(treeB);
	int* arrA = new int[sizeA];
	int* arrB = new int[sizeB];

	i = 0;
	makeInOrderArr(treeA, arrA, &i);
	i = 0;
	makeInOrderArr(treeB, arrB, &i);

	int* merged = mergeTwoArr(arrA,sizeA, arrB,sizeB);

	return sortedArrToBST(merged, 0, sizeA + sizeB - 1);
}

void inOrderTreeWalk(BSTNode* root)
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
	int a[5] = { 2,3,4,5,8 };
	int b[3] = { 1,6,7 };

	BSTNode* root1 = sortedArrToBST(a, 0, 4);
	BSTNode* root2 = sortedArrToBST(b, 0, 2);

	BSTNode* result = mergeTwoBST(root1, root2);

	inOrderTreeWalk(result);

	system("pause");
    return 0;
}

