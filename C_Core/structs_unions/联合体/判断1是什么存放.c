#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check()
{
	union Un
	{
		int x;
		char y;
	}s;
	s.x = 1;
	return s.y;
}

int main()
{
	int a = 1;
	int ret = check();

	if (ret == 1)
		printf("小端存放\n");
	else
		printf("大端存放\n");
	return 0;
}