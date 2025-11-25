#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

typedef int ListDateType;

typedef struct CeqList
{
	ListDateType* arr;
	int size;
	int capecity;
}SL;

// 函数指针类型：头插操作
typedef void (*SLPushFrontFunc)(SL*, ListDateType);
// 函数指针类型：尾插操作
typedef void (*SLPushBackFunc)(SL*, ListDateType);
// 函数指针类型：头删操作
typedef void (*SLPopFrontFunc)(SL*);
// 函数指针类型：尾删操作
typedef void (*SLPopBackFunc)(SL*);
// 函数指针类型：指定位置插入操作（假设SLPush的签名是 void SLPush(SL*, int 位置, SLDataType 元素)）
typedef void (*SLPushPosFunc)(SL*, int, ListDateType);
// 函数指针类型：指定位置删除操作（假设SLPop的签名是 void SLPop(SL*, int 位置)）
typedef void (*SLPopPosFunc)(SL*, int);

//定义顺序表
void CaqListInit(SL* ps);

//尾插
void SLPushBack(SL* ps, ListDateType x);

//头插
void SLPushFront(SL* ps, ListDateType x);

//随机加入元素
void SLPush(SL* ps, int pos, ListDateType x);

//随机删除
void SLPop(SL* ps, int pos);

//尾删元素
void SLPopBack(SL* ps);

//头删
void SLPopFront(SL* ps);

//顺序表销毁
void SLDestory(SL* ps);

//打印元素
void SLPrint(SL ps);