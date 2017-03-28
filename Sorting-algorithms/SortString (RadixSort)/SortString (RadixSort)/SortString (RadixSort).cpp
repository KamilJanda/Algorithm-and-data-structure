// SortString (RadixSort).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void sortByPos(char** arr,int length[],int size,int from,int to,int pos)
{
	int count[26] = { 0 };
	char** tmp = new char*[size];
	int* tmpLength=new int[size];
	int ascii;

	for (int i = from; i < size; i++)
	{
		ascii = int(arr[i][pos]) - 'a';
		count[ascii]++;
	}

	for (int i = 1; i < 26; i++)count[i] += count[i - 1];

	for (int i = to; i >= from; i--)
	{
		ascii= int(arr[i][pos]) - 'a';
		tmp[count[ascii] - 1] = arr[i];
		tmpLength[count[ascii] - 1] = length[i];
		count[ascii]--;
	}

	int j = 0;
	for (int i = from; i <=to; i++)
	{
		arr[i] = tmp[j];
		length[i] = tmpLength[j];
		j++;
	}

	delete[] tmp;
	delete[] tmpLength;
}

void sortByLength(char** arr,int* length,int size,int maxLen)
{

	int* count=new int[maxLen];
	char** tmp = new char*[size];
	int* tmpLen = new int[size];

	for(int i=0;i<maxLen;i++)count[i] = 0;

	for (int i = 0; i < size; i++)
	{
		count[length[i] - 1]++;
	}

	for (int i =1; i < maxLen; i++) count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		tmp[count[length[i]-1] - 1] = arr[i];
		tmpLen[count[length[i]-1] - 1] = length[i];
		count[length[i]-1]--;
	}

	for (int i = size - 1; i >= 0; i--)
	{
		arr[i]=tmp[i];
		length[i]=tmpLen[i];
	}


	delete[] count;
	delete[] tmp;
	delete[] tmpLen;
}

void stringSort(char** arr, int size)
{
	int max = 0;
	int* length = new int[size];
	for (int i = 0; i < size; i++)
	{
		length[i] = strlen(arr[i]);
		if (max < length[i])max = length[i];
	}
		

	sortByLength(arr,length,size,max);

	int pos = length[size - 1]-1;
	int from = size - 1;

	for (pos ; pos>=0 ;pos-- )
	{
		while (from > 0&&pos==length[from-1]-1)from--;
		sortByPos(arr,length,size,from,size-1,pos);
	}


}

int main()
{
	char** test = new char*[3];

	test[0] = "abcz";
	test[1] = "bc";
	test[2] = "adcd";

	stringSort(test, 3);

	for (int i = 0; i < 3; i++)cout << test[i] << " ";


	getchar();
    return 0;
}

