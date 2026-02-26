#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;
//定义双向链表节点的结构
typedef struct ListNode
{
	LTDataType data;          //数据域：存储节点数据
	struct ListNode* next;    //前驱指针：指向前一个节点
	struct ListNode* prev;    //后驱指针：指向后一个节点
}ListNode;

//声明双向链表中提供的方法

//初始化
void ListInit(ListNode** PPhead);

//尾插
void ListPushBack(ListNode* Phead, LTDataType x);//插入数据之前，链表必须初始化到只有一个头节点的额情况

//打印
void ListPrint(ListNode* Phead);

//头插
void ListPushFront(ListNode* Phead, LTDataType x);

//尾删
void ListPopBack(ListNode* Phead);

//头删
void ListPopFront(ListNode* Phead);

//查找节点
ListNode* ListFind(ListNode* Phead, LTDataType x);

//指定位置之后插入数据
void ListInsert(ListNode* pos, LTDataType x);

//指定位置之前插入数据
void ListInsertend(ListNode* pos, LTDataType x);

//删除指定节点
void ListPop(ListNode* pos);

//双向链表的销毁
void ListDesTroy(ListNode* Phead);