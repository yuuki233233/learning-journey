#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void find(int (*p)[10], int len, int x)//传入二维的一维数组
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d ", *(*(p + i) + j));//等价于p[i][j]
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][10] = { {1,2,3,4,5,6,7,8,9,10},{11,22,33,44,55,66,77,88,99,1010},{111,222,333,444,555,666,777,888,999,101010} };
	int len = sizeof(arr) / sizeof(arr[0]);
	find(arr, len, 10);
}