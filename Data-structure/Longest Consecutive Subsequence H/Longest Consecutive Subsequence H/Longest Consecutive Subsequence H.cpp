// Longest Consecutive Subsequence H.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Hash Table stuff
struct HT
{
	int key;
	int status;
	/* -1=lazy delete, 0=empty, 1=occupied */
};

struct HashTable
{
	HT* arr;
	int size;

	HashTable(int x)
	{
		size = x;
		arr = new HT[size];
		for (int i = 0; i < size; i++) arr[i].status = 0;
	}
};

int h1(int key,int size)
{
	return key%size;
}

int h(int key, int size,int i)
{
	return (h1(key, size) + i) % size;
}

void insert(HashTable* ht, int key)
{
	int ix;
	int size = ht->size;

	for (int i = 0; i < size; i++)
	{
		ix = h(key, size, i);

		if (ht->arr[ix].status != 1)
		{
			ht->arr[ix].key = key;
			ht->arr[ix].status = 1;
			return;
		}
	}
}

int search(HashTable* ht, int key)
{
	int ix;
	int size = ht->size;

	for (int i = 0; i < size; i++)
	{
		ix = h(key, size, i);
		if (ht->arr[ix].status == 1 && ht->arr[ix].key == key) return ix;
		else if (ht->arr[ix].status == 0) return -1;
	}
	return -1;
}

bool find(HashTable* ht, int key)
{
	int ix;
	int size = ht->size;

	for (int i = 0; i < size; i++)
	{
		ix = h(key, size, i);
		if (ht->arr[ix].status == 1 && ht->arr[ix].key == key) return true;
		else if (ht->arr[ix].status == 0) return false;
	}
	return false;
}

void remove(HashTable* ht, int key)
{
	int size = ht->size;
	int id = search(ht, key);

	if (id != -1)
	{
		ht->arr[id].status = -1;
	}
}

void printHT(HashTable* ht, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ht->arr[i].key << " ";
	}
}

//end of Hash Table stuff

void findLongestConseqSubseq(int arr[], int n)
{
	HashTable* ht = new HashTable(n);
	for (int i = 0; i < n; i++)
	{
		insert(ht, arr[i]); //O(n)
	}

	int maxLength = 0;
	int currentLength = 0;
	int startNumber;

	for (int i = 0; i < n; i++)
	{
		if (find(ht,arr[i]-1)==false)
		{
			currentLength = 1;
			for (int j = 1; j < n; j++)
			{
				if (find(ht,arr[i]+j)==true) currentLength++;
				else break;
			}

			if (currentLength > maxLength)
			{
				startNumber = arr[i];
				maxLength = currentLength;
			}
		}
	}

	cout << "Length of the Longest contiguous subsequence is " << maxLength << endl;
	for (int i = 0; i < maxLength; i++)
	{
		int id = search(ht, startNumber + i);
		cout << ht->arr[id].key << " ";
	}
}

int main()
{
	const int n = 7;
	int test[n]= {1, 9, 3, 10, 4, 20, 2};

	findLongestConseqSubseq(test, n);



	system("pause");
    return 0;
}
