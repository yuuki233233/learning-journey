#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//打开文件(存在的情况下)
	FILE* ps = fopen("test.txt", "r");
	if (ps == NULL)
	{
		perror("fopen");
		return 1;
	}

	//读文件
	int ch = 0;
	while ((ch = fgetc(ps)) != EOF)
	{
		printf("%c", ch);
	}

	//关闭文件
	fclose(ps);
	ps = NULL;

	return 0;
}