// InorderTreeWalk without Recursion.cpp : Defines the entry point for the console application.
//

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

void inOrderTreeWalk(BSTNode* root)
{
	stackNode* stack = NULL;

	bool done = false;
	BSTNode* current = root;


	while (!done)
	{
		if (current != NULL)
		{
			push(stack, current);
			current = current->left;
		}
		else
		{
			if (isEmpty(stack) == false)
			{
				current = pop(stack);
				cout << current->key << " ";
				current = current->right;
			}
			else done = true; //or return
		}
	}
}

int main()
{
	BSTNode* root = new BSTNode(10);
	root->left = new BSTNode(5);
	root->left->left = new BSTNode(2);
	root->left->right = new BSTNode(8);
	root->right = new BSTNode(20);

	inOrderTreeWalk(root);


	system("pause");
	return 0;
}