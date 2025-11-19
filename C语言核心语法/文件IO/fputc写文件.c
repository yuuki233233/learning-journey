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

	int ch = 0;
	for (ch = 'a'; ch < 'z'; ch++)
	{
		//输入字符
		fputc(ch, ps);
	}

	//关闭文件
	fclose(ps);
	ps = NULL;

	return 0;
}