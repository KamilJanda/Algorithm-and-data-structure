// SkipList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

struct SLNode
{
	int key;
	int height;
	SLNode** next;

	SLNode(int height, int val)
	{
		key = val;
		next = new SLNode*[height];
	}
};

struct skipList
{
	SLNode* head;
	SLNode* tail;
	int maxHeight;

	skipList(int h)
	{
		maxHeight = h;
		head = new SLNode(maxHeight, INT_MIN);
		tail = new SLNode(maxHeight, INT_MAX);
		for (int i = 0; i < maxHeight; i++)
		{
			head->next[i] = tail;
		}
	}
};

int search(skipList* skip, int key)
{
	SLNode* tmp = skip->head;

	for (int i = skip->maxHeight - 1; i >= 0; i--)
	{
		while (key > tmp->next[i]->key)
		{
			tmp = tmp->next[i];
		}
	}

	if (tmp->next[0]->key == key) return key;
	return -1;
}

int getLevel(int max)
{
	int h = 1;

	while ((double)rand() / RAND_MAX < 0.5)
	{
		h++;
	}
	
	if (h <= max) return h;
	return max;
}

void insert(skipList* skip,int key)
{
	int lvl = getLevel(skip->maxHeight);
	SLNode* item = new SLNode(lvl, key);

	SLNode* tmp = skip->head;

	for (int i = skip->maxHeight - 1; i >= 0; i--)
	{
		while (key > tmp->next[i]->key)
		{
			tmp = tmp->next[i];
		}

		if (i < lvl)
		{
			item->next[i] = tmp->next[i];
			tmp->next[i] = item;
		}
	}
}

void remove(skipList* skip, int key)
{
	SLNode* tmp = skip->head;

	for (int i = skip->maxHeight - 1; i >= 0; i--)
	{
		while (key>tmp->next[i]->key)
		{
			tmp = tmp->next[i];
		}

		if (tmp->next[i]->key == key)
		{
			tmp->next[i] = tmp->next[i]->next[i];
		}
	}

	tmp = tmp->next[0];

	if (tmp->key == key)
	{
		delete tmp;
	}
}

void showList(skipList* skip)
{
	SLNode* tmp = skip->head;

	for (int i = skip->maxHeight - 1; i >= 0; i--)
	{
		tmp = skip->head->next[i];
		while (tmp!=skip->tail)
		{
			cout << tmp->key << " ";
			tmp = tmp->next[i];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	skipList* list = new skipList(10);

	insert(list, 1);
	insert(list, 2);
	insert(list, 7);
	insert(list, 3);

	for (int i = 0; i < 20; i++)
	{
		insert(list, rand() % 10);
	}

	showList(list);

	insert(list, 6);

	showList(list);

	system("pause");
    return 0;
}

