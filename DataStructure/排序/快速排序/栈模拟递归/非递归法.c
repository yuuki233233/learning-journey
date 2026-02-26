#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

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
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int PartSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	int keyi = left;
	int prev = left;
	int cur = prev + 1;

	while (cur <= right)
	{
		if (arr[cur] < arr[keyi] && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}

		cur++;
	}
	Swap(&arr[prev], &arr[keyi]);

	return prev;
}

void QuickSortNonR(int* arr, int left, int right)
{
	ST st;
	STInit(&st);
	//放入栈里面
	STPush(&st, right);
	STPush(&st, left);

	while (!STEmpty(&st))
	{
		//将最值取出
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		//找到基准数
		int keyi = PartSort(arr, begin, end);

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

int main()
{
	int arr[] = { 3,8,0,6,2,7,9,5,1,2 };
	int len = sizeof(arr) / sizeof(arr[0]);

	QuickSortNonR(arr, 0, len - 1);
	PrintSort(arr, len);

	return 0;
}