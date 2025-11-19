#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void find_num(int* p, int len)
{
	int* left = p;
	int* right = p + len - 1;
	while (left < right)
	{
		while (left < right && *left % 2 == 1)
		{
			left++;
		}
		while (left < right && *right % 2 == 0)
		{
			right--;
		}
		int tmp = *left;
		*left = *right;
		*right = tmp;
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	find_num(arr, len);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", *(arr + i));
	}
	return 0;
}