#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义顺序表的结构

//#define N 100
//
////静态顺序表
//struct SeqList
//{
//	int arr[N];
//	int size;//有效数组个数
//};

typedef int SLDataType;
//动态顺序表
typedef struct SeqList
{
	int* arr;
	int size;//有效数据个数
	int capecity;//空间大小
}SL;

//typedef struct SeqList SL;

//判断内存够不够
void SLCheckCapacity(SL* ps);

//初始化
void SLInit(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);

//头插
void SLPushFront(SL* ps, SLDataType x);

//销毁地址
void SLDestory(SL* ps);

//打印顺序表
void SLPrint(SL ps);

//删除第一个元素
void SLPopFront(SL* ps);

//插入指定位置
void SLInsert(SL* ps, int pos, SLDataType x);

//删除指定位置
void SLErase(SL* ps, int pos);

//删除最后一个元素
void SLPopBack(SL* ps);

//查找
int SLFind(SL* ps, SLDataType x);