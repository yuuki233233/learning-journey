#define _CRT_SECURE_NO_WARNINGS
#include"11_23.h"

void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
		return;

	int mid = (right + left) / 2;
	
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid+1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;

	int j = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if(a[begin1] <= a[begin2])
		{
			tmp[j++] = a[begin1++];
		}
		else
		{
			tmp[j++] = a[begin2++];
		}
	}

	while(begin1 <= end1)
	{
		tmp[j++] = a[begin1++];
	}

	while(begin2 <= end2)
	{
		tmp[j++] = a[begin2++];
	}

	memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
}

// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [begin1, end1][begin2, end2]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			if (begin2 >= n)
				break;

			if (end2 >= n)
				end2 = n - 1;

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}

// 计数排序
void CountSort(int* a, int n)
{
	int min = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];

		if (max < a[i])
			max = a[i];
	}
	int range = max - min + 1;

	int* count = (int*)calloc(range, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
	
	free(count);
	count = NULL;
}