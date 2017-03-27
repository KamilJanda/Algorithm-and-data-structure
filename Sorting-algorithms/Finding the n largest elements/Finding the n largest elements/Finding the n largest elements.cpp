// Finding the n largest elements.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int partition(int arr[], int p, int r)
{
	int pivot = arr[r];
	int i = p - 1;
	int j;

	for (j = p; j < r; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[j]);
	return i + 1;
}

void quickSort(int arr[], int p, int r)
{
	while (p < r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		p = q + 1;
	}
}

void insertionSort()
{

}

int select(int arr[], int p, int r, int i)
{
	if (p == r) return arr[p];

	int q = partition(arr, p, r);
	int k = q - p + 1;	//size of first part of array 
	if (i == k) return arr[q];
	else if (i < k)return select(arr, p, q - 1, i);
	else return select(arr, q + 1, r, i-k);
}

int* findNLargest(int arr[], int size, int n)
{
	int* result = new int[n];
	int firstOfLarge = size - n + 1;
	int idFirstOfLarge = size - n;
	result[0]=select(arr, 0, size - 1, firstOfLarge);

	quickSort(arr, idFirstOfLarge, size - 1);
	for (int i = 0; i < n; i++)result[i] = arr[idFirstOfLarge+i];
	return result;
}

int main()
{
	int arr[10] = { 9,8,3,6,5,9,5,2,1 };
	int* res = findNLargest(arr, 10, 3);

	for (int i = 0; i < 3; i++)cout << res[i] << " ";

	getchar();
	return 0;
}

