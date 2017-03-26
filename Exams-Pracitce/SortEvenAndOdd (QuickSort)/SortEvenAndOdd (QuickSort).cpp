// SortEvenAndOdd (QuickSort).cpp : Defines the entry point for the console application.

//Sort all even numbers in ascending order and then sort all odd numbers in descending order

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int partition(int arr[], int p, int r)
{
	int pivot = arr[r];
	int i=p-1;
	int j;

	for (j = p; j < r; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	i++;
	swap(arr[i], arr[j]);
	return i;
}
void quickSort(int arr[], int p, int r)
{
	if (p < r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

int partition(int arr[], int p, int r,char reverse)
{
	int pivot = arr[r];
	int i=p-1;
	int j;

	for (j = p; j < r; j++)
	{
		if (arr[j] > pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	i++;
	swap(arr[i], arr[j]);
	return i;
}
void quickSort(int arr[], int p, int r, char reverse)
{
	if (p < r)
	{
		int q = partition(arr, p, r,'x');
		quickSort(arr, p, q - 1,'r');
		quickSort(arr, q + 1, r,'r');
	}
}

void evenOddSort(int arr[], int size)
{
	int i, j;
	i = -1;
	j = size;

	while (i<j)
	{
		do { j--; } while (j >= 0 && arr[j] % 2 == 0);

		do { i++; } while (i < size&&arr[i] % 2 != 0);

		if (i < j)swap(arr[i], arr[j]);
	}

	quickSort(arr, 0, j,'r');
	quickSort(arr, j + 1, size - 1);
}

int main()
{
	int test[10] = { 4,2,5,4,6,8,13,3,0,1 };
	
	//quickSort(test, 0, 9, 'r');
	evenOddSort(test, 10);

	for (int i = 0; i < 10; i++)cout<<test[i] << " ";

	system("pause");
    return 0;
}

