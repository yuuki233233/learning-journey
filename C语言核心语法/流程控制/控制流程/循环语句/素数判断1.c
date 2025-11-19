#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		int flag = 1;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;//证明不是素数
				break;
			}
			
		}
		if (flag == 1)//是素数
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d", count);
	return 0;
}