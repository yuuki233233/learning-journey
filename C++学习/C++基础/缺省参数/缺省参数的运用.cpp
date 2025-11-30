#define _CRT_SECURE_NO_WARNINGS
//使用前提：需要将栈的代码加进来


// Stack.h
#include<iostream>
#include<assert.h>
using namespace std;

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pS, int n = 4);

// Stack.cpp
#include"Stack.h"
//缺省参数不能声明和定义同时给
void STInit(ST* pS，int n)
{
	assert(ps && n > 0);

	ps->a = (STDataType*)malloc(n * sizeof(STDataType));
	ps->top = 0;
	ps->capacity = n;
}

//test.cpp
#include"Stack.h"
int main()
{
	ST s1;
	STInit(&s1);
	//确定知道要插入1000个数据，初始化时一把开好，避免扩容
	ST s2;
	STInit(&s2, 1000);
	return 0;
}