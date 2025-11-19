#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char* GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
void Test(void)
{
	char* str = NULL;
	//str指向p地址
	str = GetMemory();
	//p地址销毁，str却指向p(野指针)
	printf(str);
}
int main()
{
	Test();
	return 0;
}