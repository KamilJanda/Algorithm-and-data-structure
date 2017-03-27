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
	node* currentCheck=list;
	node* sentinel = new node;
	sentinel->next = list;
	node* tmp = sentinel;
	node* move;


	while (currentCheck->next != NULL&&currentCheck->key < currentCheck->next->key)
	{
		tmp = currentCheck;
		currentCheck = currentCheck->next;
	}

	move = currentCheck;
	tmp->next = currentCheck->next;


	tmp = sentinel;
	while (tmp->next != NULL&&tmp->next->key<move->key)
	{
		tmp = tmp->next;
	}

	move->next = tmp->next;
	tmp->next = move;


	return sentinel->next;
}


int main()
{
	node* list = NULL;
	node* fixed;

	push_back(&list, 10);
	push_back(&list, 4);
	push_back(&list, 5);
	push_back(&list, 6);

	fixed = fixSortedList(list);
	show(fixed);

	getchar();
    return 0;
}

