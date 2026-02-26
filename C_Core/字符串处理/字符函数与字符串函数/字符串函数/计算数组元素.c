#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>//¶ÏÑÔÍ·ÎÄ¼þ

size_t my_strlen(const char* arr)
{
	if (*arr != '\0')
	{
		return 1 + my_strlen(arr + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char arr[] = "hallo world";
	size_t len = my_strlen(arr);
	printf("%zu\n", len);
	return 0;
}