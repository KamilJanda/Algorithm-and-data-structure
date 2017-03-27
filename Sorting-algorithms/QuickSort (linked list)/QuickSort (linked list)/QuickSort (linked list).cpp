// QuickSort (linked list).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct node
{
	int key;
	node* next = NULL;
};

class List
{
public:
	const int size;
	List(int sizeOfList);
	~List();
	void push_front(node* &head, int data);
	void push_front(node* &head, node* data);
	void moveFromTo(node *& source, node *& destination);
	node* mergeTwoList(node* first, node* second);
	void partition(node* list, node* &p, node* &q, node* &r);
	node* quickerSort(node* list);
	void show();
//private:
	node* head;
};

List::List(int sizeOfList)
	:head(NULL),
	size(sizeOfList)
{
	int rd;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		rd=rand()%101;
		push_front(head, rd);
	}
}
 //to do 
List::~List()
{
	//delete head;
} 
void List::push_front(node* &head, int data)
{
	node* tmp = new node;
	tmp->key = data;
	tmp->next = head;
	head = tmp;
}
void List::push_front(node* &head, node* data)
{
	data->next = head;
	head = data;
}

void List::moveFromTo(node* &source, node* &destination)
{
	node* move = source;
	source = source->next;
	List::push_front(destination, move);
}

node * List::mergeTwoList(node * first, node * second)
{
	node* result = first;
	node* tmp = result;

	while (tmp->next != NULL)tmp = tmp->next;
	tmp->next = second;
	return result;
}

void List::partition(node* list, node* &p, node* &q, node* &r)
{
	if (list == NULL) return;
	p = NULL;
	q = NULL;
	r = NULL;
	int pivot = list->key;
	node* move;

	while (list != NULL)
	{
		if (list->key < pivot)moveFromTo(list, p);
		else if (list->key > pivot)moveFromTo(list, r);
		else moveFromTo(list, q);
	}
}

node* List::quickerSort(node* list)
{
	if (list!=NULL&&list->next!=NULL)
	{
		node* sorted = NULL;
		node *p, *q, *r;
		node* tmp;

		partition(list, p, q, r);

		p=quickerSort(p);
		r=quickerSort(r);

		if (p != NULL)
		{
			sorted = mergeTwoList(p, q);
			if (r != NULL) mergeTwoList(sorted, r);
		}
		else
		{
			sorted = mergeTwoList(q, r);
		}
		return sorted;
	}
}

void List::show()
{
	node * tmp = this->head;
	while (tmp != NULL)
	{
		cout << tmp->key << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

int main()
{
	List list(20);

	list.head=list.quickerSort(list.head);

	list.show();

	system("pause");
    return 0;
}

