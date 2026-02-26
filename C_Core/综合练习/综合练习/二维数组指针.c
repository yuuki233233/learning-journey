#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[3][4] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
	int* p[3] = { arr[0],arr[1],arr[2] };

	//指针数组笔记中有解释
	//sizeof(arr) / sizeof(arr[0]) == 3
	//sizeof(arr[0]) / sizeof(arr[0][0]) == 4
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}

	//把二维数组当成一维数组
	int* p = arr[0];
	for (int i = 0; i < 12; i++)
	{
		printf("%d ", p[i]);
	}

	return 0;
}

