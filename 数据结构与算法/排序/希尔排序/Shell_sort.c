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

//希尔排序(多组并行)
void Shell_sort01(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

//希尔排序(一组一组排序)
void Shell_sort02(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < gap; i++)
		{
			for (int j = i; j < n - gap; j += gap)
			{
				int end = j;
				int tmp = arr[end + gap];
				while (end >= 0)
				{
					if (tmp < arr[end])
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				arr[end + gap] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 9,6,3,7,4,0,7,4,2,6,1 };
	int len = sizeof(arr) / sizeof(int);

	Shell_sort01(arr, len);
	PrintSort(arr, len);

	Shell_sort02(arr, len);
	PrintSort(arr, len);

	return 0;
}