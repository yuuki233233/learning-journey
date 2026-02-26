#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void PrintSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void CountSort(int* arr, int n)
{
	//循环遍历找最值
	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}

		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int range = max - min + 1;

	//申请初始化的空间
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("calloc fail");
		return;
	}

	//统计次数
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++; 
	}

	//排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[j++] = i + min;
		}
	}

	free(count);
	count = NULL;
}

int main()
{
	int arr[] = { 4,7,5,1,8,5,3,6,9 };
	int len = sizeof(arr) / sizeof(arr[0]);

	CountSort(arr, len);
	PrintSort(arr, len);
	return 0;
}