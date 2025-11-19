#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

int my_strcmp(char* arr1, char* arr2)
{
	assert(arr1 && arr2);
	while (*arr1 == *arr2)
	{
		if (*arr1 == '\0')
			return 0;
		arr1++;
		arr2++;
	}

	if (*arr1 > *arr2)
		return 1;
	if (*arr1 < *arr2)
		return -1;
}

int main()
{
	char arr1[] = "hallo";
	char arr2[] = "hallo";
	int set = my_strcmp(arr1, arr2);
	printf("%d\n", set);
	return 0;
}