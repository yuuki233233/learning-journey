#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n = 0;
	printf("输入的行为:> ");
	scanf("%d", &n);

	int m = 0;
	printf("输入的列为:> ");
	scanf("%d", &m);

	int arr[n][m];

	int i = 0, j = 0;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
		{
			printf("第%d行第%d列为:> ",i + 1,j + 1);
			scanf("%d", & arr[i][j]);
		}
		printf("\n");
	}

	printf("矩阵转置为:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}
	return 0;
}