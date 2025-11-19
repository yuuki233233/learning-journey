#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[3][5] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		printf("请输入二维数组第%d的值:>\n",i + 1);
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}

	printf("打印二维数组的值\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}