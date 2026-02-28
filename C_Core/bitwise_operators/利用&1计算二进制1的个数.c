#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//int n = 13;
	//00000000 00000000 00000000 00001101  13
	//n = n >> 1;
	//00000000 00000000 00000000 00000001  1
	//00000000 00000000 00000000 00000001  ∞¥Œª”Î
	int n = 0;
	scanf("%d", &n);
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((n >> i) & 1) == 1)
		{
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}