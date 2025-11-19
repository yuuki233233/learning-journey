#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f1()
{
	printf("helloworld\n");
}

int main()
{
	void (*p)(); //定义指针函数
	p = f1;
	p();         //通过函数指针调用函数 等价于 f1()

	return 0;
}