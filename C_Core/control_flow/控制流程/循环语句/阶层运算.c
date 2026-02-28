#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = 1;
	int sum = 0;

	for (int j = 1; j <= n; j++)
	{
		ret *= j;
		printf("%d ", ret);
		sum += ret;
	} 
	printf("\n");
	printf("%d", sum);
	return 0;
}