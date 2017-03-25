// Select.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int partition(int arr[], int p, int r) //p- id of first element, r- id of last element
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
	swap(arr[i],arr[j]);

	return i;
}

int select(int arr[], int p, int r, int posOfElement) //posOfElement <1,n>
{
	if (p == r)	return arr[p];

	int q = partition(arr, p, r);

	int sizeOfLeftArr = q - p+1;

	if (posOfElement < sizeOfLeftArr)
	{
		select(arr, p, q-1, posOfElement);
	}
	else if (posOfElement>sizeOfLeftArr)
	{
		select(arr, q + 1, r, posOfElement-sizeOfLeftArr);
	}
	else
	{
		return arr[q];
	}
}

int partition1(int arr[], int p, int r)
{
	int pivot = arr[p];
	int i, j;
	i = p - 1;
	j = r + 1;

	do
	{
		j--;
	} while (arr[j]>pivot);
	
	do
	{
		i++;
	} while (arr[i]<pivot);

	if (i < j)swap(arr[i], arr[j]);
	else return j;

}

int select1(int arr[], int p, int r, int id)
{
	if (r == p) return arr[p];


}

int main()
{
	int test[5] = { 5,4,3,2,1 };

	cout << select(test, 0, 4, 1);

	system("pause");
    return 0;
}

