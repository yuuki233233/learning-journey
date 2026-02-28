#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int add(int x, int y)
{
	return x + y;
}

typedef int(*T)(int, int);

int main()
{
	T p1 = add;  //µÈ¼ÛÓÚ int(*p)(int,int);
	printf("%d", p1(1, 3));

	return 0;
}