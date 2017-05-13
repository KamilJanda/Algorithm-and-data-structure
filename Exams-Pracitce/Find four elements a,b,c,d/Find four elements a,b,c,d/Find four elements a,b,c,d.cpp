// Find four elements a,b,c,d.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct pair_int
{
	int x,y;
};

struct HTable
{
	int size;
	int* sum;
	pair_int* numbers;
	int* status;

	HTable(int x)
	{
		size = x;
		sum = new int[size];
		numbers = new pair_int[size];
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
	return (h1(key, size) + 1) % size;
}


void insert(HTable* ht, int sum,int x,int y)
{
	int id;

	for (int i = 0; i < ht->size; i++)
	{
		id = h(sum, ht->size, i);

		if (ht->status[id] != 1)
		{
			ht->sum[id] = sum;
			ht->numbers[id].x = x;
			ht->numbers[id].y = y;
			ht->status[id] = 1;
			return;
		}
	}
}

int find(HTable* ht, int sum)
{
	int id;

	for (int i = 0; i < ht->size; i++)
	{
		id = h(sum, ht->size, i);

		if (ht->status[id] == 1 && ht->sum[id] == sum) return id;
		else if (ht->status[id] == 0) return -1;
	}
	return -1;
}

bool findPairs(int arr[], int n)
{
	HTable* ht = new HTable(n);
	int sum;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum = arr[i] + arr[j];

			if (find(ht, sum)!=-1)
			{
				int id = find(ht, sum);

				cout << ht->numbers[id].x << "+" << ht->numbers[id].y << "=" << arr[i] << "+"<<arr[j];

				return true;
			}
				
			else insert(ht, sum, arr[i], arr[j]);
		}
	}

	return false;
}

int main()
{
	const int n = 7;
	int test[7] = { 3, 4, 7, 1, 2, 9, 8 };

	findPairs(test, n);

	system("pause");
    return 0;
}

