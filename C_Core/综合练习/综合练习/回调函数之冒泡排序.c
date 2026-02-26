#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int less(int x, int y)
{
	return (x > y) ? 1 : 0;
}

int greater(int x, int y)
{
	return (x < y) ? 1 : 0;
}


void swp(int* arr, int len, int (*p)(int, int))
{
	int i = 0;
	for (i = 0; i < len - 1; i++)
	{
		int j = 0;
		for (j = 0; j < len - 1 - i; j++)
		{
			// if (arr[j] > arr[j + 1])
			if (p(arr[j], arr[j + 1]))   //通过函数指针调用函数
			{
				//交换
				int t = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = t;
			}
		}
	}
}

int main()
{
	int arr[] = { 4,6,7,1,3,8,3,9,2,4,6,8,4 };
	int len = sizeof(arr) / sizeof(arr[0]);

	//冒泡函数
	swp(arr, len, less);
	
	//打印排序后的数组
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	swp(arr, len, greater);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}