// FixSortedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node
{
	int key;
	node* next;
};

void show(node* head)
{
	while (head != NULL)
	{
		std::cout << head->key << " ";
		head = head->next;
	}
	std::cout << "\n";
}

void push_back(node** head, int data)
{
	node* newNode = new node;
	newNode->next = NULL;
	newNode->key = data;
	while (*head != NULL)head = &((*head)->next);

	*head = newNode;
	newNode->next = NULL;
}

node* fixSortedList(node* list)
{
	node* move;
	node* prev;
	node* current;
	node* sentinel=new node;
	

	if (list->key > list->next->key)
	{
		move = list;
		list = list->next;
	}
	else
	{
		prev = list;
		current = list->next;

		
		while (current->next != NULL)
		{
			if (prev->key < current->key&&current->key < current->next->key)
			{
				prev = prev->next;
				current = current->next;
			}
			else if (!(prev->key < current->next->key))
			{
				prev = prev->next;
				current = current->next;
			}
			else
			{
				break;
			}
		}
		

		if (current->next == NULL&&prev->key > current->key);
		{
			move = current;
			prev->next = current->next;
		}

		move = current;
		prev->next = current->next;
	}

	sentinel->next = list;
	prev = sentinel;

	while (prev->next != NULL&&prev->next->key < move->key)prev = prev->next;

	move->next = prev->next;
	prev->next = move;


	return sentinel->next;
}



int main()
{
	node* list = NULL;
	node* fixed;

	push_back(&list, 1);
	push_back(&list, 2);
	push_back(&list, 333);
	push_back(&list, 6);
	push_back(&list, 7);
	push_back(&list, 8);
	push_back(&list, 9);
	push_back(&list, 10);




	fixed = fixSortedList(list);
	show(fixed);

	getchar();
    return 0;
}

