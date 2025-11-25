#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

//void SLTTest01()
//{
//	//手动创建每个节点
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	//将节点中的数据给赋值
//	node1->data = 1;
//
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	node2->data = 2;
//
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	node3->data = 3;
//
//	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
//	node4->data = 4;
//
//	//让每个节点相互连接
//	node1->Next = node2;
//	node2->Next = node3;
//	node3->Next = node4;
//	node4->Next = NULL;
//
//	//创建一个指针，指向列车的开头
//	SLTNode* Phead = node1;
//
//	//传入列车的开头，然后打印单链表
//	SLTPrint(Phead);
//}

//void SLTTest02()
//{
//	//申请一个节点
//	SLTNode* node1 = NULL;
//
//	//让一个指针指向第一个节点
//	SLTNode* Phead = node1;
//
//	//不能传入形参，要传入地址
//	SLTPushBack(&Phead, 1);
//
//	//头插
//	SLTPushFront(&Phead, 2);
//
//	//打印单链表
//	SLTPrint(Phead);
//
//	//尾删
//	SLTPopBack(&Phead);
//
//	//头删
//	SLTPopFront(&Phead);
//
//	//查找
//	SLTNode* Find = SLTFind(Phead, 3);
//	if (Find == NULL)
//	{
//		printf("没找到!!\n");
//	}
//	else
//	{
//		printf("找到了!!\n");
//	}
//
//	//打印单链表
//	SLTPrint(Phead);
//}

void SLTTest03()
{
	SLTNode* node1 = NULL;
	
	SLTNode* Phead = node1;
	//尾插
	SLTPushBack(&Phead, 1);
	//尾插
	SLTPushBack(&Phead, 2);
	//尾插
	SLTPushBack(&Phead, 3);
	//打印链表的头函数
	SLTPrint(Phead);//1 2 3

	//查找
	SLTNode* find = SLTFind(Phead, 4);
	//在指定位置之前插入数据
	SLTInsert(&Phead, find, 4);
	//打印链表的头函数
	SLTPrint(Phead);//1 2 3 4

	//查找
	SLTNode* find1 = SLTFind(Phead, 4);
	//在指定位置之后插入数据
	SLTInserAfter(find1, 5);
	//打印链表的头函数
	SLTPrint(Phead);//1 2 3 4 5

	//查找
	SLTNode* find2 = SLTFind(Phead, 4);
	//删除对应节点
	SLTErase(&Phead, find2);
	//打印链表的头函数
	SLTPrint(Phead);//1 2 3 5

	//查找
	SLTNode* find3 = SLTFind(Phead, 2);
	//删除指定位置之后的节点
	SLTEraseAfter(find3);
	//打印链表的头函数
	SLTPrint(Phead);//1 2 5

	//销毁
	SLTDesTroy(&Phead);
}

int main()
{
	//SLTTest01();
	//SLTTest02();
	SLTTest03();
	return 0;
}