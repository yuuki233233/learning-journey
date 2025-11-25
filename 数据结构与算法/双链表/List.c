#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

//申请节点
ListNode* LTBuyNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		perror("maloc fail!");
		exit(1);
	}
	node->data = x;
	//双向链表的节点要自己指向自己
	node->next = node->prev = node;

	return node;
}

//初始化
void ListInit(ListNode** PPhead)
{
	//给链表创建一个哨兵位
	*PPhead = LTBuyNode(-1);

}

//尾插
void ListPushBack(ListNode* Phead, LTDataType x)
{
	assert(Phead);

	ListNode* newnode = LTBuyNode(x);

	//让新节点的尾指向后面的节点，头指向哨兵位
	newnode->prev = Phead->prev;
	newnode->next = Phead;

	//让后面的节点的前指向新节点，然后把尾节点往后移
	Phead->prev->next = newnode;
	Phead->prev = newnode;
}

//打印
void ListPrint(ListNode* Phead)
{
	//双向链表是个循环，先让指针指向哨兵位的前一个节点
	//当循环到哨兵位时，退出循环
	ListNode* Pcur = Phead->next;
	while (Pcur != Phead)
	{
		printf("%d->", Pcur->data);
		Pcur = Pcur->next;
	}
	printf("\n");
}

//头插
void ListPushFront(ListNode* Phead, LTDataType x)
{
	assert(Phead);

	ListNode* newnode = LTBuyNode(x);

	//与尾插的思维相同，画图分析
	newnode->next = Phead->next;
	newnode->prev = Phead;

	//需改变的节点：Phead newnode Phead->next;
	//两行代码不能完全交换
	Phead->next->prev = newnode;
	Phead->next = newnode;
}

//尾删
void ListPopBack(ListNode* Phead)
{
	assert(Phead && Phead->next != Phead);

#if 0
	//方案1：
	
	//让被删除的上一个节点，指向头节点
	Phead->prev->prev->next = Phead;

	//指向好了，就把尾节点释放掉
	ListNode* scr = Phead->prev;
	free(scr);
	scr = NULL;

	//让头节点的尾指向被删除的上一个节点
	Phead->prev = Phead->prev->prev;
#endif

#if 1
	//方案2：

	//创建一个被删除节点的变量
	ListNode* del = Phead->prev;

	//Phead del->prev del
	Phead->prev = del->prev;
	del->prev->next = Phead;

	//释放掉删除的节点
	free(del);
	del = NULL;
#endif
}

//头删
void ListPopFront(ListNode* Phead)
{
	assert(Phead && Phead->next != Phead);

#if 0
	//让头节点指向被删除的下一个节点
	//1.必须先把被删除的下一个节点用指针保存起来
	//2.因为在释放内存时，空指针不能解引用
	ListNode* PheadNext = Phead->next->next;

	//手动释放被删除的空间
	//1.将第一个节点释放时，需要一个指针接收
	//2.因为在释放时，不用指针接收的地址释放，就会产生未初始化的指针解引用
	ListNode* scr = Phead->next;
	free(scr);
	scr = NULL;

	//让头节点指向被删除的下一个节点
	Phead->next = PheadNext;


	//让被删除的下一个节点，指向头节点
	Phead->next->next->prev = Phead;
#endif

#if 1
	ListNode* del = Phead->next;

	//Phead del->next del
	//指向第二个节点
	Phead->next = del->next;
	//指向哨兵位
	del->next->prev = Phead;

	//手动释放删除的节点
	free(del);
	del = NULL;
#endif
}

//查找节点
ListNode* ListFind(ListNode* Phead, LTDataType x)
{
	ListNode* pcur = Phead->next;

	while (pcur != Phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//指定位置之后插入数据
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	//接收新节点
	ListNode* newnode = LTBuyNode(x);

	//让新节点指向pos节点
	newnode->prev = pos;
	//让新节点指向pos前一个节点
	newnode->next = pos->next;

	//让pos节点前一个节点的后面指向新节点
	pos->next->prev = newnode;
	//让pos节点指向新节点
	pos->next = newnode;
}

//指定位置之前插入数据
void ListInsertend(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newnode = LTBuyNode(x);

	//让新节点前面指向pos节点
	newnode->next = pos;
	//让新节点后面指向pos后一个节点
	newnode->prev = pos->prev;

	//让pos后一个节点的前面指向新节点
	pos->prev->next = newnode;
	//让pos后一个指向新节点
	pos->prev = newnode;
}

//删除指定节点
void ListPop(ListNode* pos)
{
	assert(pos);

	//pos->perv pos pos->next
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;

	free(pos);
	pos = NULL;
}

//双向链表的销毁
void ListDesTroy(ListNode* Phead)
{
	ListNode* pcur = Phead->next;

	//销毁节点，剩下头节点(哨兵位)
	while (pcur != Phead)
	{
		ListNode* next = pcur->next;
		free(pcur);
		pcur = NULL;
		pcur = next;
	}
	//此时pcur指向Phead，而Phead还没有被销毁
	free(Phead);
	Phead = NULL;
}