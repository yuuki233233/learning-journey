#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// 快速排序前后指针法
void PartSort3(int* a, int left, int right)
{
	if (left >= right)//只有一个元素或不存在，停止递归
		return;

	int keyi = left;

	int prev = left;//前指针
	int cur = prev + 1;//后指针
	while (cur <= right)//cur越界结束循环
	{
		//cur一直向后走，遇到小的值就停下，让prev向前走一步并交换
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		cur++;
	}
	Swap(&a[keyi], &a[prev]);//出循环，将prev停留位置与keyi位置进行交换
	keyi = prev;

	PartSort3(a, left, keyi - 1);
	PartSort3(a, keyi + 1, right);
}