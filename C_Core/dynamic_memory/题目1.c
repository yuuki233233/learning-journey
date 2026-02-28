#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#if 0
//错误代码分析
void GetMemory(char* p)
{
	//形参是实参的临时拷贝
	p = (char*)malloc(100);
	//p不会影响str
}
void Test(void)
{
	char* str = NULL;
	GetMemory(str);
	//p指向申请空间，当p离开函数时，p的生命周期结束(地址释放)
	//str原本指向p，但地址已经释放
	strcpy(str, "hello world");
	printf(str);
}

int main()
{
	Test();
	return 0;
}




//正确代码1

void GetMemory(char** p)
{
	//p指向str的地址
	*p = (char*)malloc(100);
}

void Test(void)
{
	char* str = NULL;
	//传入指针的地址
	GetMemory(&str);
	strcpy(str, "hallo world");
	printf(str);
}

int main()
{
	Test();
	return 0;
}
#endif




//正确代码2
char* GetMemory(char* p)
{
	p = (char*)malloc(100);
	return p;
}

void Test(void)
{
	char* str = NULL;
	str = GetMemory(str);

	strcpy(str, "hallo world");
	printf(str);
}

int main()
{
	Test();
	return 0;
}