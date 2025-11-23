#include"11_22.h"

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		while (begin < end && a[keyi] <= a[end])
		{
			end--;
		}
		while (begin < end && a[keyi] >= a[begin])
		{
			begin++;
		}
		Swap(&a[end], &a[begin]);
	}
	Swap(&a[keyi], &a[begin]);
	
	return begin;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	int key = a[left], keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		while (begin < end && key <= a[end])
		{
			end--;
		}
		if (begin < end)
			a[begin] = a[end];

		while (begin < end && key >= a[begin])
		{
			begin++;
		}
		if (begin < end)
			a[end] = a[begin];
	}
	a[begin] = key;
	return begin;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = left;
	int prev = left, cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}

void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = PartSort1(a, left, right);

	QuickSort1(a, left, keyi - 1);
	QuickSort1(a, keyi + 1, right);
}

void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = PartSort2(a, left, right);

	QuickSort2(a, left, keyi - 1);
	QuickSort2(a, keyi + 1, right);
}

void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = PartSort3(a, left, right);

	QuickSort3(a, left, keyi - 1);
	QuickSort3(a, keyi + 1, right);
}

#include"Stack.h"
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);

	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		int keyi = PartSort3(a, begin, end);

		//[begin, keyi - 1] keyi [keyi + 1, end]
		if (keyi + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}

		if (keyi - 1 > begin)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
	}
}