#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>

int main()
{
	//fopen以读的形式打开文件，若文件不存在，就打开失败

	//将文件传到pf，并打开pf
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		//若文件不存在，打印错误
		perror("zhangsan");
		return 1;
	}

	//关闭pf
	fclose(pf);

	return 0;
}