#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* Next;
}SLTNode;

//打印链表的头函数
void SLTPrint(SLTNode* Phead);

//尾插
void SLTPushBack(SLTNode** PPhead, SLTDataType x);

//头插
void SLTPushFront(SLTNode** PPhead, SLTDataType x);

//尾删
void SLTPopBack(SLTNode** PPhead);

//头删
void SLTPopFront(SLTNode** PPhead);

//查找
SLTNode* SLTFind(SLTNode* Phead, SLTDataType x);

//在指定位置之前插入数据
SLTNode* SLTInsert(SLTNode** PPhead, SLTNode* pos, SLTDataType x);

//在指定位置之后插入数据
SLTNode* SLTInserAfter(SLTNode* pos, SLTDataType x);

//删除节点
void SLTErase(SLTNode** PPhead, SLTNode* pos);

//删除指定位置之后的节点
void SLTEraseAfter(SLTNode* pos);

//销毁链表(销毁一个一个的节点)
void SLTDesTroy(SLTNode** PPhead);