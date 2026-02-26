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

	//写文件
	fputs("hello world\n", ps);
	fputs("hello bit\n", ps);

	//关闭文件
	fclose(ps);
	ps = NULL;

	return 0;
}