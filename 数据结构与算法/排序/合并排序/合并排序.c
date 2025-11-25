#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;

	//取中间值，分两边递归
	int mid = (end + begin) / 2;
	//递归排序
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	//设立新变量，更易于比较
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;

	//设置下标，归并
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		//将两组中的元素进行比较，然后排序
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//一边走完，另一边没走完
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//将数据拷贝给a数组中
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	//思路：将获取的元素放进新的数组中，然后拷贝到a数组中
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	//设立子函数，将数据放进里面递归排序
	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

int main()
{
	int a[] = { 4,9,7,2,6,3,5,1,0,8 };
	int len = sizeof(a) / sizeof(a[0]);

	MergeSort(a, len);
	PrintSort(a, len);

	return 0;
}