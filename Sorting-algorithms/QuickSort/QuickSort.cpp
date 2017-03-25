// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include<time.h>


using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int arr[], int p, int r)
{
	int pivot = arr[p];
	int i, j;

	i = p - 1;
	j = r + 1;
	while (1)
	{
		do { j--; } while (arr[j] > pivot);
		do { i++; } while (arr[i] < pivot);

		if (i < j)swap(arr[i], arr[j]);
		else return j;
	}
}


int randomizedPartition(int arr[], int p, int r)
{
	srand(time(NULL));
	int rd = (rand() % (r + 1 - p)) + p;
	swap(arr[p], arr[rd]);
	return partition(arr, p, r);
}

void randomizedQuickSort(int arr[], int p, int r)
{
	if (p < r)
	{
		int q = randomizedPartition(arr, p, r);

		randomizedQuickSort(arr, p, q);
		randomizedQuickSort(arr, q + 1, r);
	}
}

int main()
{
	int test[3] = { 5,4,1 };

	randomizedQuickSort(test, 0, 2);

	cout << test[0];

	system("pause");
    return 0;
}

