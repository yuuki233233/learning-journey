#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>//м╥нд╪Ч

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8 };
	int arr2[] = { 1,2,3,4,8,8,8,8 };
	int num1 = memcmp(arr1, arr2, 4 * sizeof(int));
	int num2 = memcmp(arr1, arr2, 5 * sizeof(int));

	printf("%d\n", num1);
	printf("%d", num2);

	return 0;
}