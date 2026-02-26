#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int sum = 0;
	int arr[5];
	int len = sizeof(arr) / sizeof(arr[0]);

	printf("请输入5个整数:\n");
	for (int i = 0; i < len; i++)
	{
		printf("请输入第%d个整数:> ",i + 1);
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("输入的数总和为:%d\n", sum);
	printf("输入的数的平均数为:%.2f\n", (float)sum / len);
	return 0;
}