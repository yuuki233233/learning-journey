#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct
{
	char name;
	int age;
	int id;
}s = { 'x',18,100 };

int main()
{
	printf("%c %d %d\n", s.name, s.age, s.id);
	return 0;
}