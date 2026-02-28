#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strcpy(char* arr1, char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	
	char* ret = arr1;
	while (*arr2++ = *arr1++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[] = "hallo world";
	char arr2[20] = { 0 };

	char* ret = my_strcpy(arr1, arr2);

	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", ret);
	return 0;
}