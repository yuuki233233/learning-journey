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

//插入排序
void insertion_sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			//从小到大排序
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		//将数据插入到空位
		arr[end + 1] = tmp;
	}
}

int main()
{
	int arr[] = { 9,6,3,7,4,0,7,4,2,6,1 };
	int len = sizeof(arr) / sizeof(int);

	insertion_sort(arr, len);
	PrintSort(arr, len);

	return 0;
}