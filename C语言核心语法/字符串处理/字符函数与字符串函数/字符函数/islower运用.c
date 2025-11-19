#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>

int main()
{
	int i = 0;
	char arr[] = "hallo world";
	while (arr[i] != '\0')
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] -= 32;
		}
		i++;
	}
	printf("%s\n", arr);
	return 0;
}