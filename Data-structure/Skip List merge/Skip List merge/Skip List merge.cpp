// Skip List merge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct SLNode
{
	int key;
	int hegiht;
	SLNode** next;
	SLNode(int key, int height)
	{
		this->hegiht = hegiht;
		this->key = key;
		next = new SLNode*[height];
	}
};

struct skipList
{
	SLNode* head;
	SLNode* tail;
	int maxHeight;

	skipList(int maxHeight)
	{
		this->maxHeight = maxHeight;
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

		while (key>tmp->next[i]->key)
		{
			tmp = tmp->next[i];
		}

		if (tmp->next[0]->key == key) return key;
	}

	return -1;
}


int getLevel(int max)
{
	int lvl = 1;

	while ((double)rand()/RAND_MAX<0.5)
	{
		lvl++;
	}

	if (lvl < max) return lvl;
	else return max;
}

void insert(skipList* skip,SLNode* item)
{
	SLNode* tmp = skip->head;

	for (int i = skip->maxHeight - 1; i >= 0; i--)
	{

		while ((item->key)>(tmp->next[i]->key))
		{
			tmp = tmp->next[i];
		}

		if (i < item->hegiht)
		{
			item->next[i] = tmp->next[i];
			tmp->next[i] = item;
		}
	}
}

void pop_front(skipList* skip,SLNode* toRemove)
{

	for (int i = skip->maxHeight - 1; i >= 0; i--)
	{
		if(skip->head->next[i]==toRemove)
		{
			skip->head->next[i] = toRemove->next[i];
		}
	}

}

skipList* merge(skipList* &a, skipList* &b)
{
	SLNode* tmpA = a->head;
	SLNode* tmpB = b->head;
	SLNode* move;

	int maxLvl = max(a->maxHeight, b->maxHeight);

	skipList* result = new skipList(maxLvl);

	while (tmpA->next[0]!=a->tail&&tmpB->next[0]!=b->tail)
	{
		if (tmpA->next[0]->key < tmpB->next[0]->key)
		{
			move = tmpA->next[0];
			pop_front(a, move);
			insert(result, move);
		}
		else
		{
			move = tmpB->next[0];
			pop_front(b, move);
			insert(result, move);
		}
	}

	
	while (tmpA->next[0] != a->tail)
	{
		move = tmpA->next[0];
		pop_front(a, move);
		insert(result, move);
	}

	while (tmpB->next[0] != b->tail)
	{
		move = tmpB->next[0];
		pop_front(b, move);
		insert(result, move);
	}

	return result;
}


int main()
{


	system("pause");
    return 0;
}

