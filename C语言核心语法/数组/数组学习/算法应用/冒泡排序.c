#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[] = { 6,3,8,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("打印前的数组元素:");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("打印后的数组元素:");
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1; j++)//len-1为i的前一位,让相邻的元素进行比较大小
		{
			if (arr[j] < arr[i])//假设最大元素在j上
			{
			    int max = arr[j];//设最大为arr[j],然后进行交换
				arr[j] = arr[i];
				arr[i] = max;
			}
		}
	}
	for (int i = 0; i < len; i++)//交换完,打印元素
	{
		printf("%d ", arr[i]);
	}
	return 0;
}