// Two nodes of a BST are swapped.cpp : Defines the entry point for the console application.
//Two nodes of a BST are swapped, correct the BST

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct BSTNode
{
	BSTNode *p, *left, *right;
	int key;

	BSTNode(int x)
	{
		key = x;
		left = NULL;
		right = NULL;
	}
};

void correctBSTUtil(BSTNode* root,BSTNode* &prev,BSTNode* &first,BSTNode* &middle,BSTNode* &second) //O(n)
{
	if (root != NULL)
	{
		correctBSTUtil(root->left, prev, first, middle, second);

		if (prev != NULL&&prev->key>root->key)
		{
			if (first == NULL)
			{
				first = prev;
				middle = root;
			}
			else second = root;
		}
		
		prev = root;

		correctBSTUtil(root->right, prev, first, middle, second);
	}
}

void correctBST(BSTNode* root)
{
	BSTNode* prev, *first, *middle, *second;
	prev = first = middle = second = NULL;

	correctBSTUtil(root, prev, first, middle, second);

	if (first!=NULL&&second != NULL)
	{
		swap(first->key, second->key);
	}
	else if (first != NULL&&middle != NULL)swap(first->key, middle->key);

}

void inOrder(BSTNode* root)
{
	if (root)
	{
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}

int main()
{
	BSTNode* root = new BSTNode(10);
	root->left = new BSTNode(5);
	root->left->left = new BSTNode(2);
	root->left->right = new BSTNode(20);
	root->right = new BSTNode(8);

	correctBST(root);

	inOrder(root);

	system("pause");
    return 0;
}

