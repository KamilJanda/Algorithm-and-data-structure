// Find pair in A[] with sum x hash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct hashTable
{
	int size;
	int* arr;
	int* status; //-1 lazy delete, 0- empty, 1- occupied
	hashTable(int size)
	{
		this->size = size;
		arr = new int[size];
		status = new int[size];
		for (int i = 0; i < size; i++) status[i] = 0;
	}
};

int h1(int key, int size)
{
	return key%size;
}

int h(int key, int size, int i)
{
	return (h1(key, size) + i) % size;
}

void insert(hashTable* ht, int key)
{
	int id;

	for (int i = 0; i < ht->size; i++)
	{
		id = h(key, ht->size, i);
		if (ht->status[id] != 1)
		{
			ht->status[i] = 1;
			ht->arr[i] = key;
		}
	}
}

bool find(hashTable* ht, int key)
{
	int id;

	for (int i = 0; i < ht->size; i++)
	{
		id = h(key, ht->size, i);
		if (ht->status[id] == 1 && ht->arr[id] == key) return true;
		else if (ht->status[id] == 0) return false;
	}
	return false;
}

bool findPair(int arr[], int n,int sum)
{
	int tmp;
	hashTable* ht = new hashTable(n);

	for (int i = 0; i < n; i++)
	{
		insert(ht, arr[i]);
	}


	for (int i = 0; i < n; i++)
	{
		tmp = sum - arr[i];

		if (tmp >= 0 && find(ht, tmp) == true)
		{
			cout << tmp << "+" << arr[i] << "=" << sum;
			return true;
		}
	}
	return false;
}


int main()
{
	const int n = 6;
	int A[n] = { 1, 4, 45, 6, 10, 8 };

	findPair(A, n, 16);



	system("pause");
    return 0;
}

