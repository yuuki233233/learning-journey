#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[] = { 11,22,33,44,55,66,77,88,99 };
	int len = sizeof(arr1) / sizeof(arr1[0]);

	printf("第一个数组元素为:> ");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");

	printf("第二个数组元素为:> ");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr2[i]);
	}

	for (int j = 0; j < len; j++)
	{
		int temp = arr1[j];
		arr1[j] = arr2[j];
		arr2[j] = temp;
	}
	printf("\n");

	printf("合并后的数组为:> ");
	for (int j = 0; j < len; j++)
	{
		printf("%d ", arr1[j]);
	}
	printf("\n");
	return 0;
}