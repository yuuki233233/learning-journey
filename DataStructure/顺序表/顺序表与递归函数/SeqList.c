#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

//定义顺序表
void CaqListInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capecity = 0;
}

//判断内存够不够
void SLCheckCapecity(SL* ps)
{
	if (ps->capecity == ps->size)
	{
		//第一种情况，都为0
		//用三目运算符
		int NewCapecity = ps->capecity == 0 ? 4 : ps->capecity * 2;

		//第二种情况，空间不够
		//开辟新空间，tmp来接受
		ListDateType* tmp = (ListDateType*)realloc(ps->arr, NewCapecity * sizeof(ListDateType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		//空间申请成功
		ps->arr = tmp;
		ps->capecity = NewCapecity;
	}
}

//尾插
void SLPushBack(SL* ps, ListDateType x)
{
	assert(ps);

	SLCheckCapecity(ps);

	ps->arr[ps->size] = x;
	ps->size++;
}

//头插
void SLPushFront(SL* ps, ListDateType x)
{
	assert(ps);

	SLCheckCapecity(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	ps->size--;
}

//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//指定位置插
void SLPush(SL* ps, int pos, ListDateType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapecity(ps);

	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1]; //arr[pos + 1] = arr[pos]
	}
	ps->arr[pos] = x;
	ps->size++;
}

//随机删除
void SLPop(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i - 1] = ps->arr[i];//arr[pos] = arr[pos + 1]
	}
	ps->size--;
}

//打印元素
void SLPrint(SL ps)
{
	for (int i = 0; i < ps.size; i++)
	{
		printf("%d ", ps.arr[i]);
	}
	printf("\n");
}

//顺序表的销毁
void SLDestory(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
	}
	ps->capecity = ps->size = 0;
}