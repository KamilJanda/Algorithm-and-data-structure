// MergeSortedLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

struct node
{
	int key;
	node* next;
	node();
};
node::node()
{
	next = NULL;
}

void show(node* head)
{
	while (head != NULL)
	{
		std::cout << head->key << " ";
		head = head->next;
	}
	std::cout << "\n";
}

void push_back(node** head, node* newNode)
{
	while (*head != NULL)head = &((*head)->next);

	*head = newNode;
	newNode->next = NULL;
}

node* mergeSortedLinkedList(node** arrOfNode,int size)
{
	node* sorted = NULL;
	node* move;
	bool nodeExist = true;
	int idOfMin;

	while (nodeExist)
	{
		nodeExist = false;

		for (int i = 0; i < size; i++)
		{
			if (arrOfNode[i]!=NULL)
			{
				if (nodeExist == false)
				{
					idOfMin = i;
					nodeExist = true;
				}

				if (arrOfNode[i]->key < arrOfNode[idOfMin]->key)idOfMin = i;
			}
		}
		if (nodeExist)
		{
			move = arrOfNode[idOfMin];
			arrOfNode[idOfMin] = arrOfNode[idOfMin]->next;
			push_back(&sorted, move);
		}
	}

	return sorted;
}

int main()
{
	int size = 3;
	node** arr = new node*[size];
	for (int i = 0; i < size; i++)arr[i] = NULL;

	for (int i = 0; i < 5; i++)
	{
		node* x = new node;
		x->key = i + 7;
		push_back(&arr[0], x);
	}
	for (int i = 0; i < 3; i++)
	{
		node* x = new node;
		x->key = i + 2;
		push_back(&arr[1], x);
	}
	for (int i = 10; i < 16; i++)
	{
		node* x = new node;
		x->key = i;
		push_back(&arr[2], x);
	}


	node* test = mergeSortedLinkedList(arr, size);

	show(test);


	system("pause");
    return 0;
}

