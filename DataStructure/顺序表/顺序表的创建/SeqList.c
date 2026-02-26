#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

//顺序表的初始化
void SLInit(SL* s)
{
	s->arr = NULL;
	s->size = s->capecity = 0;
}

//判断内存够不够
void SLCheckCapacity(SL* ps)
{
	if (ps->capecity == ps->size)
	{
		//第一种情况，都为0
		//用三目运算符
		int NewCapecity = ps->capecity == 0 ? 4 : ps->capecity * 2 * sizeof(SLDataType);

		//第二种情况，空间不够
		//开辟新空间，tmp来接受
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, NewCapecity * sizeof(SLDataType));
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

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	//判断是否为空指针
	assert(ps);

	//判断内存够不够
	SLCheckCapacity(ps);

	//往后各挪一位
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//arr[1] = arr[0]
	}
	ps->arr[0] = x;
	ps->size++;
}

//删除第一个元素
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);//防止空表删除，直接报错提醒！

	//从第二个元素开始，依次往前挪移一位，覆盖第一个元素
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	//有效元素减1
	ps->size--;
}


//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	//判断是否为空指针
	assert(ps);

	//判断内存够不够
	SLCheckCapacity(ps);

	//尾插入
	ps->arr[ps->size++] = x;
}

//删除最后一个元素
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	//有效元素减1，后面的空间相当于“废弃”
	ps->size--;
}

//顺序表的销毁
void SLDestory(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capecity = 0;
}

//打印顺序表
void SLPrint(SL sp)
{
	for (int i = 0; i < sp.size; i++)
	{
		printf("%d ", sp.arr[i]);
	}
	printf("\n");
}

//随机插入元素
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size && pos >= 0);
	//插入数据：空间够不够
	SLCheckCapacity(ps);
	//让pos及之后的数据整体往后挪移1位
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//arr[pos + 1] = arr[pos]
	}
	ps->arr[pos] = x;
	ps->size++;
}

//删除指定位置
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	SLCheckCapacity(ps);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];//arr[size - 2] = arr[size - 1]
	}
	ps->size--;
}

//查找
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->arr[i])
		{
			//找到了
			return i;
		}
	}
	//没有找到
	return -1;
}