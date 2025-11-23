#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;// 存储元素的数组
	int top;      // 栈顶指针（指向栈顶元素的下标）
	int capacity; // 栈的最大容量（支持动态扩容）
}ST;

//初始化和销毁
void STInit(ST* pst);
void STDestroy(ST* pst);

//入栈  出栈
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

//获取栈顶的数据
STDataType STTop(ST* pst);

//判空
bool STEmpty(ST* pst);

//获取数据个数
int STSize(ST* pst);