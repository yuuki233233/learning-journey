#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

union Un
{
	int a;
	char b;
};

int main()
{
	union Un u = { 0 };
	
	printf("%p\n", &u);
	printf("%p\n", &u.a);
	printf("%p\n", &u.b);

	u.a = 0x11223344;
	u.b = 0x55;

	return 0;
}