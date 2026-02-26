#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 快速排序挖坑法
void PartSort2(int* a, int left, int right)
{
	if (left >= right)//只有一个元素或不存在，停止递归
		return;

	int keyi = left;
	int key = a[left];//先将基准值存下来

	int begin = left, end = right;
	while (begin < end)
	{
		while (begin < end && key <= a[end])//右找大，找到停下来，填到左边的坑
		{
			end--;
		}
		if (begin < end)
			a[begin] = a[end];

		while (begin < end && key >= a[begin])//左找小，找到停下来，填到右边的坑
		{
			begin++;
		}
		if (begin < end)
			a[end] = a[begin];
	}
	a[begin] = key;//相遇之后，将保存的值填到相遇位置
	keyi = begin;

	PartSort2(a, left, keyi - 1);
	PartSort2(a, keyi + 1, right);
}