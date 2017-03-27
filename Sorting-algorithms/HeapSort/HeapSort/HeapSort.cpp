// HeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

static class Heap
{
public:
	static void heapify(int arr[], int size, int i);
	static void buildHeap(int arr[], int size);
	static void heapSort(int arr[], int size);
	static int extractMax(int arr[],int size);
	static void show(int arr[], int size);
	static void insert(int arr[],int heapSize,int size,int data);
};

void Heap::heapify(int arr[], int size,int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	int max = i;

	if (left<size&&arr[left] > arr[max])max = left;
	if (right<size&&arr[right] > arr[max])max = right;


	if (max != i)
	{
		swap(arr[i], arr[max]);
		heapify(arr, size, max);
	}

}

void Heap::buildHeap(int arr[], int size)
{
	int start = (size - 2) / 2;

	for (int i = start; i >= 0; i--)
	{
		heapify(arr, size, i);
	}
}

void Heap::heapSort(int arr[], int size) //to do
{
	buildHeap(arr, size);
	for (int i = size-1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr,i, 0);
	}
}

int Heap::extractMax(int arr[],int size)
{
	int max;
	size = size - 1;
	max = arr[0];
	arr[0] = arr[size];
	heapify(arr, size,0);

	return max;
}

void Heap::show(int arr[],int size)
{
	for (int i = 0; i < size; i++)cout << arr[i] << " ";
	cout << endl;
}

void Heap::insert(int arr[], int heapSize, int size, int data)
{
	heapSize++;

	int i = heapSize - 1;
	int father = (i - 1) / 2;
		
	while (i > 0 && arr[father] < data)
	{
		arr[i] = arr[father];
		i = father;
		father = (i - 1) / 2;
	}

	arr[i] = data;
}

int main()
{
	const int s = 5;
	int test[s] = { 3,4,1,5,0 };

	Heap::buildHeap(test, 4);

	//Heap::heapSort(test, s);

	Heap::show(test, 4);

	Heap::insert(test, 4, 5, 13);

	Heap::show(test, 5);



	system("pause");
    return 0;
}

