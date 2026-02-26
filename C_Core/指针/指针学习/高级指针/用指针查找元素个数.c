#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int find_len(char* arr)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}

int main()
{
	char arr[] = { "hallo" };
	int len = find_len(arr);
	printf("%d ", len);
	return 0;
}