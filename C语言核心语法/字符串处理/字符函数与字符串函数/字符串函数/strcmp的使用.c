#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	int s = strcmp(arr1, arr2);
	return s;
}

int main()
{
	char arr1[] = "hallo";
	char arr2[] = "hallo";
	int set = my_strcmp(arr1, arr2);
	printf("%d\n", set);
	return 0;
}