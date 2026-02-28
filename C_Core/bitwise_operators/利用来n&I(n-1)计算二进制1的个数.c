#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n = 0;
	scanf("%d", & n);
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	printf("%d\n", count);

	return 0;
}