// FindTheLargestSubarrayWith0Sum H.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct hashTable
{
	int* key;
	int* value;
	int* status;
	int size;

	hashTable(int x)
	{
		size = x;
		key = new int[size];
		value = new int[size];
		status = new int[size];
		for (int i = 0; i < size; i++)status[i] = 0;
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

void insert(hashTable* ht,int key,int val)
{
	int id;

	for (int i = 0; i < ht->size; i++)
	{
		id = h(key, ht->size, i);
		if (ht->status[id] != 1)
		{
			ht->key[id] = key;
			ht->value[id] = val;
			ht->status[id] = 1;
			return;
		}
	}
}

int find(hashTable* ht,int key)
{
	int id;

	for (int i = 0; i < ht->size; i++)
	{
		id = h(key, ht->size, i);

		if (ht->status[id] == 1 && ht->key[id] == key) return ht->value[id];
		else if (ht->status[id] == 0) return -1;
	}
	return -1;
}

int largestSubarrayWith0Sum(int arr[], int size)
{
	hashTable* ht = new hashTable(size);
	int sum = 0;
	int currentLength;
	int maxLength = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];

		if (arr[i] == 0) maxLength = max(maxLength,1); //case if 0 is first element

		if (sum == 0) maxLength = i + 1;	//case {-2,2,...} sum={-2,0,...}

		if (find(ht, sum) != -1)
		{
			maxLength = max(maxLength, i - find(ht, sum));
		}
		else
		{
			insert(ht, sum, i);
		}
	}

	return maxLength;
}


int main()
{
	const int n = 8;
	int test[n]= { 15, -2, 2, -8, 1, 7, 10, 23 };

	cout << largestSubarrayWith0Sum(test, n);


	system("pause");
    return 0;
}

