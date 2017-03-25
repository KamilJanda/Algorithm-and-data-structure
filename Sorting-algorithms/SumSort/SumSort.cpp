// SumSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;


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
int select(int arr[], int p, int r, int id)
{
	if (p == r)return arr[p];

	int q = partition(arr, p, r);

	int k = q - p + 1;

	if (id <= k) select(arr, p, q, id);
	else select(arr, q + 1, r, id - k);
}


int partition1(int arr[], int p, int r) //p- id of first element, r- id of last element
{
	int pivot = arr[r];
	int i, j;

	i = p - 1;
	for (j = p; j < r; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	i = i + 1;
	swap(arr[i], arr[j]);

	return i;
}
int select1(int arr[], int p, int r, int posOfElement) //posOfElement <1,n>
{
	if (p == r)	return arr[p];

	int q = partition1(arr, p, r);

	int sizeOfLeftArr = q - p + 1;

	if (posOfElement < sizeOfLeftArr)
	{
		select1(arr, p, q - 1, posOfElement);
	}
	else if (posOfElement>sizeOfLeftArr)
	{
		select1(arr, q + 1, r, posOfElement - sizeOfLeftArr);
	}
	else
	{
		return arr[q];
	}
}

void sumSort(int A[], int B[], int n)
{
	int size = n*n;

	for (int i = 0; i < size; i++)B[i] = A[i];

	int first = 0;
	int last = size - 1;

	for (int i = n - 1; i < size; i += n)
	{
		select1(B, first, last, i + 1);
		first = i + 1;
	}
}

int main()
{
	int test[9] = { 3,2,4,6,1,9,1,12,7 };
	int res[9];
	sumSort(test, res, 3);

	for (int i = 0; i < 9; i++)cout << res[i] << " ";


	system("pause");
	return 0;
}