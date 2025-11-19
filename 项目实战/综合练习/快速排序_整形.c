#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void find_set(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

void input_set(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, len, sizeof(arr[0]), find_set);
	input_set(arr, len);
	return 0;
}

