#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#pragma pack(1)//设置默认对齐数为1
struct S
{
	char c1;
	int i;
	char c2;
};
#pragma pack()//取消设置的对齐数，还原为默认
int main()
{
	//输出的结果是什么？
	printf("%d\n", sizeof(struct S));
	return 0;
}