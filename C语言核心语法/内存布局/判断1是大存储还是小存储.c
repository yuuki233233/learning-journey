#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int my_num(int* x)
{
	//求单个字节，转化为char*
	char* n = (char*)x;
	//判断是哪个存储
	if (*n == 1)
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	int n = 1;
	int i = my_num(&n);
	if (i == 1)
		printf("小段字节存储");
	else
		printf("大端字节存储");

	return 0;
}