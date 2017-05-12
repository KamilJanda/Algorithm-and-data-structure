// Find a pair with given sum inBBST.cpp : Defines the entry point for the console application.
//Find a pair with given sum in a Balanced BST

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct BSTNode
{
	int key;
	BSTNode *p, *left, *right;
	BSTNode(int x)
	{
		key = x;
		left = NULL;
		right = NULL;
	}
};

//stack stuff

struct stackNode
{
	BSTNode* val;
	stackNode* next = NULL;
};

bool isEmpty(stackNode* stack)
{
	if (stack == NULL) return true;
	else return false;
}

void push(stackNode* &stack, BSTNode* item)
{
	stackNode* snode = new stackNode;
	snode->val = item;
	snode->next = stack;
	stack = snode;
}

BSTNode* pop(stackNode* &stack)
{
	if (!isEmpty(stack))
	{
		stackNode* del = stack;
		BSTNode* tmp = stack->val;
		stack = stack->next;

		delete del;
		return tmp;
	}
}

//end of stack stuff

bool findPair(BSTNode* root, int sum)
{
	stackNode* stackLeft = NULL;
	stackNode* stackRigh = NULL;

	bool done = false;
	bool moveLeft=true;
	bool moveRight=true;
	int currentSum;
	BSTNode* currentLeft=root;
	BSTNode* currentRight=root;

	while (true)
	{
		while (moveLeft&&currentLeft != NULL)
		{
			push(stackLeft, currentLeft);
			currentLeft = currentLeft->left;
		}
		while (moveRight&&currentRight != NULL)
		{
			push(stackRigh, currentRight);
			currentRight = currentRight->right;
		}

		if(moveLeft) currentLeft = pop(stackLeft);
		if(moveRight) currentRight = pop(stackRigh);

		if (currentLeft->key >= currentRight->key) return false;

		moveLeft = false;
		moveRight = false;

		currentSum = currentLeft->key + currentRight->key;
		if (currentSum == sum) return true;
		else if (currentSum < sum) moveLeft = true;
		else moveRight = true;

		if (moveLeft) currentLeft = currentLeft->right;
		else currentRight = currentRight->left;
	}
}

int main()
{
	BSTNode* root = new BSTNode(10);
	root->left = new BSTNode(5);
	root->left->left = new BSTNode(2);
	root->left->right = new BSTNode(8);
	root->right = new BSTNode(20);

	cout << findPair(root, 208);

	system("pause");
    return 0;
}

