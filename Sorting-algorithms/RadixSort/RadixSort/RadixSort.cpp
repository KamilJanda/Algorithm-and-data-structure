// RadixSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int findMaxLen(int arr[], int size)
{	
	int max = 0;
	int count;
	int tmp;
	for (int i = 0; i < size; i++)
	{
		count = 0;
		tmp = arr[i];
		while (tmp > 0)
		{
			tmp /= 10;
			count++;
		}
		if (count > max)max = count;
	}
	return max;
}

void countingSort(int arr[], int size,int pos)
{
	int count[10] = { 0 };
	int* tmp=new int[size];
	int id;

	for (int i = 0; i < size; i++)
	{
		id = (arr[i] / pos) % 10;
		count[id]++;
	}

	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		id = (arr[i] / pos) % 10;
		tmp[count[id]-1] = arr[i];
		count[id]--;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = tmp[i];
	}

	delete[] tmp;
}

void radixSort(int arr[],int size)
{
	int maxLen = findMaxLen(arr, size);
	int j=1;

	for (int i = 1; i <= maxLen; i++)
	{
		countingSort(arr, size, j);
		j *= 10;
	}
}

int main()
{
	int arr[10] = { 1234,1,24,1287,345,3489,999,231,23,145 };

	radixSort(arr, 10);

	for (int i = 0; i < 10; i++)cout << arr[i] << " ";

	getchar();
    return 0;
}

