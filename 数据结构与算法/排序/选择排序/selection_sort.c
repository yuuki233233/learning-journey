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

void Swap(int* x, int* y)
{
	int* tmp = *x;
	*x = *y;
	*y = tmp;
}

void selection_sort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i < end; i++)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		Swap(&arr[begin], &arr[mini]);
		//Œ Ã‚
		if (begin == maxi)
			maxi = mini;
		Swap(&arr[end], &arr[maxi]);
		begin++;
		end--;
	}
}

int main()
{
	int arr[] = { 9,4,8,5,1,0,5,1,4 };
	int len = sizeof(arr) / sizeof(int);

	selection_sort(arr, len);
	PrintSort(arr, len);

	return 0;
}