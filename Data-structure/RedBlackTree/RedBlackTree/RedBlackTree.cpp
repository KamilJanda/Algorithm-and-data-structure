// RedBlackTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct RBTNode
{
	RBTNode * parent;
	RBTNode * left=NULL;
	RBTNode * right=NULL;
	int key;
	char color='r';
};

void leftRotate(RBTNode* &root,RBTNode* &x) //O(1)
{
	RBTNode* y = x->right;

	x->right = y->left;
	if (y->left != NULL) y->left->parent = x;

	y->parent = x->parent;
	y->left = x;

	if (x->parent == NULL)root = y;
	else if (x->parent->left == x)x->parent->left = y;
	else x->parent->right = y;

	x->parent = y;
}

void rightRotate(RBTNode* &root,RBTNode* &y) //O(1)
{
	RBTNode* x = y->left;

	y->left = x->right;
	if (x->right != NULL)x->right->parent = y;

	x->parent = y->parent;
	x->left = y;

	if (y->parent == NULL)root = x;
	else if (y->parent->left == y)y->parent->left = x;
	else y->parent->right = x;

	y->parent = x;
}

RBTNode* insertBST(RBTNode* &root, int key)
{
	RBTNode* newNode = new RBTNode;
	newNode->key = key;

	if (root != NULL)
	{
		RBTNode* parent=NULL;
		RBTNode* son = root;

		while (son != NULL)
		{
			parent = son;
			if (key < parent->key)son = parent->left;
			else if (key > parent->key)son = parent->right;
			else return;
		}

		if (key < parent->key)
		{
			parent->left = newNode;
			newNode->parent = parent;
		}
		else
		{
			parent->right = newNode;
			newNode->parent = parent;
		}
	}
	else
	{
		root = newNode;
	}

	return newNode;
}

void insertRBT(RBTNode* &root, int key) //O(lg n)
{
	RBTNode* x=insertBST(root, key);
	RBTNode* y;

	while (x != root&&x->parent->color == 'r') //drugi warunke zabezpiecza przed sieganiem do root->parent->left w pierszym if w petli
	{
		if (x->parent == x->parent->parent->left)
		{
			y = x->parent->parent->right;

			if (y->color == 'r') //pierwszy przypadek gdy stryj czerwony
			{
				x->parent->color = 'b';
				y->color = 'b';
				x->parent->parent->color = 'r';
				x = x->parent->parent; //powtarzamy dla x=dziadek(x) bo moze byc zaburzona wlasnosc drzewa miedzy x i x->parent
			}
			else 
			{
				if (x == x->parent->right) //drugi przypadek gdy stryj czarny i x jest lewym synem ojca
				{
					x = x->parent;
					leftRotate(root, x);
				}
				
				x->parent->color = 'b'; //trzeci przypadek gdy strj czarny i x jest prawym synem
				x->parent->parent->color = 'r';
				rightRotate(root, x->parent->parent);
			}
		}
		else
		{

		}

		root->color = 'b';
	}

}

int main()
{

	getchar();
    return 0;
}

