#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void PrintSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubble_sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}


int main()
{
	int arr[] = { 9,4,8,5,1,0,5,1,4 };
	int len = sizeof(arr) / sizeof(int);

	bubble_sort(arr, len);
	PrintSort(arr, len);

	return 0;
}