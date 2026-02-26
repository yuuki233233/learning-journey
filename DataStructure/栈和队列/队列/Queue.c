#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

// 初始化链式队列
void QueueInit(Queue* pq)
{
	assert(pq);

	//直接解引用就可改变头指针和尾指针
	pq->phead = NULL;
	pq->ptail = NULL;
	//可看人数
	pq->size = 0;
}

// 入队：向队尾（链表尾部）添加节点
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	// 创建队列节点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		ferror("malloc fail!");
		return;
	}
	newnode->next = NULL;
	newnode->val = x;

	// 空队列：队头和队尾都指向新节点
	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else// 非空队列：尾节点next指向新节点，队尾更新
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}

	pq->size++;
}

// 出队：删除队头（链表头部）节点
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size > 0);

	// 一个节点
	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = pq->ptail;
	}
	else//多个节点	
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

// 取队头元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->phead->val;
}

//找尾
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->val;
}

//找大小
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

// 判断链式队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->size == 0;
}

// 销毁链式队列
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;

		cur = next;
	}

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}