#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}

int main()
{
	int n = 0;
	scanf("%d", &n);//1234
	print(n);

	return 0;
}