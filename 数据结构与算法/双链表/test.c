#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

void ListTest01()
{
	ListNode* node = NULL;
	ListInit(&node);
	printf("尾插\n");
	ListPushBack(node, 1);
	ListPrint(node);
	ListPushBack(node, 2);
	ListPrint(node);
	ListPushBack(node, 3);
	ListPrint(node);
	printf("\n");

	printf("头插\n");
	ListPushFront(node, 2);
	ListPrint(node);
	ListPushFront(node, 3);
	ListPrint(node);
	printf("\n");

	printf("尾删\n");
	ListPopBack(node);
	ListPrint(node);
	printf("\n");

	printf("头删\n");
	ListPopFront(node);
	ListPrint(node);
	printf("\n");

	ListNode* Find = ListFind(node, 2);
	printf("查找%d\n", Find->data);
	if (Find == NULL)
	{
		printf("没找到！\n");
	}
	else
	{
		printf("找到了！\n");
	}
	printf("\n");

	ListNode* Find1 = ListFind(node, 2);
	printf("第%d个位置之后插入\n", Find1->data);
	ListInsert(Find1, 3);
	ListPrint(node);
	printf("\n");

	ListNode* Find2 = ListFind(node, 2);
	printf("第%d个位置之后插入\n", Find2->data);
	ListInsertend(Find2, 4);
	ListPrint(node);
	printf("\n");

	ListNode* Find3 = ListFind(node, 2);
	printf("删除第%d个节点\n", Find3->data);
	ListPop(Find3);
	ListPrint(node);
	printf("\n");

	printf("销毁链表\n");
	//理论上要传二级，因为我们需要让形参的改变影响到实参，但是为了保持
	//接口一致性才传的一级
	ListDesTroy(node);
	//传一级存在的问题是，当形参Phead置为NULL后，实参node不会被修改为NULL
	//因此解决的办法是：调用完方法后手动将实参置为NULL
	node = NULL;
}

int main()
{
	ListTest01();
	return 0;
}