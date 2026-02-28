#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//联合体类型的声明
union Un
{
	char c;
	int i;
};

int main()
{
	//联合体变量的定义
	union Un u = { 0 };
	//计算变量大小
	printf("%zd\n", sizeof(u));

	return 0;
}