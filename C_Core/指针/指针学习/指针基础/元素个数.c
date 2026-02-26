#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int arr[10] = { 0 };
	int* p1 = &arr[0];
	int* p2 = &arr[9];
	printf("%zd\n", p2 - p1);
	return 0;
}