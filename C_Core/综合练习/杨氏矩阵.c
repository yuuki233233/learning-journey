#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int find_num(int arr[][3], int x, int y, int n)
{
	int i = 0;
	int j = y - 1;
	while (i < x && j >= 0)
	{

		if (arr[i][j] < n)
		{
			i++;
		}
		else if (arr[i][j] > n)
		{
			j--;
		}
		else
		{
			return 1;//返回1则找到
		}
	}
	
	return 0;//没找到
}

int main()
{
	int arr[][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int len = sizeof(arr) / sizeof(arr[0]);

	int ret = find_num(arr, 3, 3, 5);
	//用条件判断是否找到
	if (ret == 1)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}

	return 0;
}