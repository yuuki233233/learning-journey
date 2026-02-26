#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void SLTPrint(SLTNode* Phead)
{
	while (Phead)
	{
		printf("%d->", Phead->data);
		Phead = Phead->Next;
	}
	printf("NULL\n");
}

//创建节点
SLTNode* SLTByNode(SLTDataType x)
{
	//手动申请空间
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NewNode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	NewNode->data = x;
	NewNode->Next = NULL;

	return NewNode;
}

//尾插
void SLTPushBack(SLTNode** PPhead, SLTDataType x)
{
	//创建节点
	SLTNode* NewNode = SLTByNode(x);
	//情况1(只有一个节点)：若无节点，申请空间给链表
	if (*PPhead == NULL)
	{
		*PPhead = NewNode;
	}
	//情况2(有多个节点)：创建一个指针指向开头，往下遍历直到空指针停止
	else
	{
		SLTNode* Ptail = *PPhead;
		while (Ptail->Next)
		{
			Ptail = Ptail->Next;
		}
		Ptail->Next = NewNode;
	}
}

//头插
void SLTPushFront(SLTNode** PPhead, SLTDataType x)
{
	//判断是否为空链表
	assert("PPhead");
	assert("*PPhead");

	//创建新节点
	SLTNode* NewNode = SLTByNode(x);

	//将空间置于前面
	NewNode->Next = *PPhead;
	//把指针指向新空间
	*PPhead = NewNode;
}

//尾删
void SLTPopBack(SLTNode** PPhead)
{
	assert(*PPhead && PPhead);

	//情况1：只有一个节点
	if ((*PPhead)->Next == NULL)
	{
		//把唯一的节点删除
		free(*PPhead);
		*PPhead = NULL;
	}
	//情况2：有多个节点
	else
	{
		//设立两个指针，一个指向结尾，一个指向结尾前一项
		SLTNode* Ptail = *PPhead;
		SLTNode* Ptailadd = *PPhead;
		//让指针遍历到结尾
		while (Ptail->Next)
		{
			Ptailadd = Ptail;
			Ptail = Ptail->Next;
		}
		//释放结尾
		free(Ptail);
		Ptail = NULL;
		Ptailadd->Next = NULL;
	}
}

//头删
void SLTPopFront(SLTNode** PPhead)
{
	//保证传的不能为空
	assert(*PPhead && PPhead);

	//让新的指针指向节点的下一个节点
	SLTNode* Ptail = (*PPhead)->Next;
	//把首元素删除
	free(*PPhead);
	//将头指针指向上面创建好的新指针
	*PPhead = Ptail;
}

//查找
SLTNode* SLTFind(SLTNode* Phead, SLTDataType x)
{
	SLTNode* Ptail = Phead;

	while (Ptail)
	{
		if (Ptail->data == x)
		{
			return Ptail;
		}
		Ptail = Ptail->Next;
	}
	return NULL;
}

//在指定位置之前插入数据
SLTNode* SLTInsert(SLTNode** PPhead, SLTNode* pos, SLTDataType x)
{
	assert(PPhead && *PPhead);

	SLTNode* NewNode = SLTByNode(x);
	
	//情况1：当插到首节点之前
	if (*PPhead == pos)
	{
		SLTPushBack(PPhead, x);
	}
	//情况2：插到其他地方之前
	else
	{
		SLTNode* Ptail = *PPhead;
		while (Ptail->Next != pos)
		{
			Ptail = Ptail->Next;
		}
		NewNode->Next = pos;
		Ptail->Next = NewNode;
	}
}

//在指定位置之后插入数据
SLTNode* SLTInserAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* NewNode = SLTByNode(x);

	NewNode->Next = pos->Next;
	pos->Next = NewNode;
}

//删除节点
void SLTErase(SLTNode** PPhead, SLTNode* pos)
{
	assert(PPhead && *PPhead);
	assert(pos);

	//情况1：删除头节点
	if (pos == *PPhead)
	{
		SLTPopFront(PPhead);
	}
	else
	{
		SLTNode* Ptail = *PPhead;
		//情况2：删除其他节点
		while (Ptail->Next != pos)
		{
			Ptail = Ptail->Next;
		}
		Ptail->Next = pos->Next;

		free(pos);
		pos = NULL;
	}
}

//删除指定位置之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->Next);
	//定义一个指针指向要删除的节点
	SLTNode* del = pos->Next;
	//pos del del->next
	//让删除节点的前一个节点指向删除节点的后一个节点
	pos->Next = del->Next;
	//释放删除的节点并指向空
	free(del);
	del = NULL;
}

//销毁链表(销毁一个一个的节点)
void SLTDesTroy(SLTNode** PPhead)
{
	assert(PPhead && *PPhead);

	SLTNode* Pcur = *PPhead;
	while (Pcur)
	{
		SLTNode* next = Pcur->Next;
		free(Pcur);
		//让销毁节点的指针指向要销毁下一个的节点
		Pcur = next;
		//当Pcur为空，就跳出循环
	}
	*PPhead = NULL;
}