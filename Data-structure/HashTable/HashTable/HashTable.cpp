// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct hashTable
{
	int size;
	int* key=new int[size];
	int* state=new int[size];
	/* -1=lazy delete, 0=empty, 1=occupied */
};

int h(int key, int size)
{
	return key%size;
}

int h(int key,int size,int i)
{
	return (h(key,size)+i)%size;
}

void hashInsert(hashTable ht,int key) //Open Addressing
{
	int id;
	for (int i = 0; i < ht.size; i++)
	{
		id = h(key, ht.size, i);
		if (ht.state[id] != 1) break;
	}

	ht.key[id] = key;
	ht.state[id] = 1;
}

bool search(hashTable ht, int key)
{
	int id;

	for (int i = 0; i < ht.size; i++)
	{
		id = h(key, ht.size, i);
		if (ht.state[id] == 0 || ht.key[id] == key)break;
	}
	if (ht.key[id] == key) return true;
	else return false;
}

void remove(hashTable ht, int key)
{
	int id;

	for (int i = 0; i < ht.size; i++)
	{
		id = h(key, ht.size, i);
		if (ht.state == 0 || ht.key[id] == key)break;
	}
	if (ht.key[id] == key)
	{
		ht.key[id] = NULL;
		ht.state[id] = -1;
	}
}


int main()
{


	getchar();
    return 0;
}

