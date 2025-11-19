#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//打开文件
	FILE* ps = fopen("test.txt", "w");
	if (ps == NULL)
	{
		perror("fopen");
		return 1;
	}

	//读文件
	char arr[10] = { 0 };
	//最多读19个，再继续往后读，直到遇到\0再换行
	while (fgets(arr, 20, ps) != NULL)
	{
		fgets(arr, 10, ps);
	}

	//关闭文件
	fclose(ps);
	ps = NULL;

	return 0;
}