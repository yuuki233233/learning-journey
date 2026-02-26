#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	//字符串
	char arr1[] = "hallo world";
	size_t sz = strlen(arr1);
	memset(arr1, 'x', 5);
	for (int i = 0; i < sz; i++)
	{
		printf("%c", arr1[i]);
	}

	printf("\n");
	//整形数组
	int arr2[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr2) / sizeof(arr2[0]);
	memset(arr2, 0, 5 * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}