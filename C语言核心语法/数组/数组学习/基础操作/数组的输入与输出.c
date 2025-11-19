#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("请输入5个整数");
	int arr[5];
	int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len; i++)
	{
		printf("请输入第%d个整数:> ", i + 1);
		if (scanf("%d", &arr[i]) != 1)
		{
			printf("请输入整数!\n");
			while (getchar() != '\n');
			i--;
			continue;
		}
	}
	printf("您输入的数组为:> ");
	for (int j = 0; j < len; j++)
	{
		printf("%d ", arr[j]);
	}
	return 0;
}