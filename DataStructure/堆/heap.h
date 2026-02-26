#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;

typedef struct Head
{
	HPDataType* a; //物理上，堆是个数组
	int size;      //堆的大小
	int capacity;  //堆可插入的数据
}HP;

//堆的初始化
void HPInit(HP* php);

//尾插数据 + 向上排序
void HPPush(HP* php, HPDataType x);

//向上排序
void AdjustUP(HPDataType* a, int child);

//两个数组元素交换位置
void swap(HPDataType* x, HPDataType* y);

//删除头元素(先首位交换，再尾删，后向下排序)
void HPPop(HP* php);

//向下排序
void AdjustDown(HPDataType* a, int n, int zero);

//取头元素
HPDataType HPTop(HP* php);

//判空
bool HPEmpty(HP* php);

//堆的删除
void HPDestory(HP* php);

//TOP-K问题
void CreateNDate();
void topk();