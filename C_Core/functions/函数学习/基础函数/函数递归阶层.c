#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Fact(unsigned int n)
{
	if (n == 0)
		return 1;
	else
		return n * Fact(n - 1);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fact(n);
	printf("%d\n", ret);

	return 0;
}