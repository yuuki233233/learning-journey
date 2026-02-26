#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void test(int* arr, int len)
{
	while(*arr < arr + len)
	{
		printf("%d ", *arr);
		arr++;
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	test(arr,len);
	return 0;
}