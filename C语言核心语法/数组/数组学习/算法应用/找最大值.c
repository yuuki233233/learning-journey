#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[] = { 7,2,6,8,5,3,9,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("数组的元素为:");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int tamp = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > tamp)
		{
			tamp = arr[i];
		}
	}
	printf("最大的元素为:%d ", tamp);
	return 0;
}