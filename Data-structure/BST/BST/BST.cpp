// BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

class BST
{
public:
	struct BSTNode
{
	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;
	int key;
};
	BSTNode* root;
	BST();

	void makeRandTree(BST &tree);
	BSTNode* search(BSTNode* root, int key);
	BSTNode* min(BSTNode* root);
	void inorderTreeWalk(BSTNode* root);
	void preorderTreeWalk(BSTNode * root);
	void postorderTreeWalk(BSTNode* root);
	BSTNode* treeSuccessor(BSTNode* x);
	BSTNode* treePredecessor(BSTNode* x);
	void insert(BSTNode* &root, int data);
	BSTNode* remove(BSTNode* &root, int key);
};

BST::BST()
{
	BSTNode* root = NULL;
}

void BST::makeRandTree(BST &tree)
{
	tree.insert(tree.root, 10);
	tree.insert(tree.root, 5);
	tree.insert(tree.root, 3);
	tree.insert(tree.root, 4);
	tree.insert(tree.root, 15);
	tree.insert(tree.root, 1);

}

BST::BSTNode* BST::search(BSTNode* root,int key)
{
	while (root!=NULL)
	{
		if (root->key == key) return root;
		else if (root->key > key)root = root->left;
		else root = root->right;
	}
	return root;
}

BST::BSTNode* BST::min(BSTNode * root)
{
	if (root == NULL) return root;
	while (root->left != NULL)root = root->left;
	return root;
}

void BST::inorderTreeWalk(BSTNode* root)
{
	if (root != NULL)
	{
		inorderTreeWalk(root->left);
		cout << root->key << " ";
		inorderTreeWalk(root->right);
	}
}

void BST::preorderTreeWalk(BSTNode* root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preorderTreeWalk(root->left);
		preorderTreeWalk(root->right);
	}
}

void BST::postorderTreeWalk(BSTNode* root)
{
	if (root != NULL)
	{
		postorderTreeWalk(root->left);
		postorderTreeWalk(root->right);
		cout << root->key << " ";
	}
}

BST::BSTNode* BST::treeSuccessor(BSTNode* x)
{
	if (x->right != NULL) min(x->right);
	else
	{
		BSTNode* tmp = x->parent;
		while (tmp != NULL&&x == tmp->left)
		{
			x = tmp;
			tmp = tmp->parent;
		}
		return tmp;
	}
}

BST::BSTNode * BST::treePredecessor(BSTNode * x)
{
	if (x->left != NULL) min(x->left);
	else
	{
		BSTNode* tmp = x->parent;
		while (tmp != NULL&&x == tmp->left)
		{
			x = tmp;
			tmp = tmp->parent;
		}
		return tmp;
	}
}

void BST::insert(BSTNode* &root, int data)
{
	BSTNode* newData = new BSTNode;
	newData->key = data;
	newData->left = NULL;
	newData->right = NULL;

	if (root != NULL)
	{
		BSTNode* tmpParent = NULL;
		BSTNode* tmpSon = root;
		while (tmpSon!=NULL)
		{
			tmpParent = tmpSon;
			if (data < tmpSon->key)tmpSon = tmpSon->left;
			else if (data > tmpSon->key)tmpSon = tmpSon->right;
			else return;
		}

		if (data < tmpParent->key)
		{
			tmpParent->left = newData;
			newData->parent = tmpParent;
		}
		else
		{
			tmpParent->right = newData;
			newData->parent = tmpParent;
		}
	}
	else
	{
		root = newData;
	}
}

BST::BSTNode* BST::remove(BSTNode * &root, int key)
{
	BSTNode* x = search(root, key);
	BSTNode *del,*tmp;

	if (x->left == NULL || x->right == NULL) del = x;
	else del = treeSuccessor(x);
		
	if (del->left != NULL) tmp = del->left;
	else tmp = del->right;

	if (tmp != NULL) tmp->parent = del->parent;

	if (del->parent == NULL)root = tmp;
	else if (del = del->parent->left) del->parent->left = tmp;
	else del->parent->right = tmp;

	if (x != del) x->key = del->key;

	return del;
}


int main()
{
	BST tree;

	tree.makeRandTree(tree);
	tree.inorderTreeWalk(tree.root);

	cout <<endl<< "poadaj: ";
	int x;
	cin >> x;

	BST::BSTNode *tmp= tree.remove(tree.root, x);

	tree.inorderTreeWalk(tree.root);

	getchar();
	getchar();
    return 0;
}

