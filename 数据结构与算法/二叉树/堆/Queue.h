#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef struct BinaryTreeNode* QDataType;

// 链式队列节点结构
typedef struct QueueNode
{
	QDataType val;// 数据域
	struct QueueNode* next;// 指针域（指向下一个节点）
}QNode;

//解决传二级指针的问题
// 链式队列管理结构（记录队头、队尾和长度，方便操作）
typedef struct Queue
{
	QNode* phead;// 队头指针（指向头节点）
	QNode* ptail;// 队尾指针（指向尾节点）
	int size;// 队列中元素个数
}Queue;

// 初始化链式队列
void QueueInit(Queue* pq);

// 入队：向队尾（链表尾部）添加节点
void QueuePush(Queue* pq, QDataType x);

// 出队：删除队头（链表头部）节点
void QueuePop(Queue* pq);

// 取队头元素
QDataType QueueFront(Queue* pq);

//找尾
QDataType QueueBack(Queue* pq);

//找大小
int QueueSize(Queue* pq);

// 判断链式队列是否为空
bool QueueEmpty(Queue* pq);

// 销毁链式队列
void QueueDestroy(Queue* pq);