#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

//初始化和销毁
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	// top指向栈顶数据下一个位置
	pst->top = 0;

	// top指向栈顶数据
	//pst->top = -1;

	pst->capacity = 0;
}
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

//入栈  出栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);

	// 动态扩容（辅助函数）
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	// 因为top = 0,指向的是栈顶的元素，不需要像top = -1那样加1
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);// 栈空，无法出栈

	pst->top--;// 栈顶指针下移（逻辑删除，无需真正清除数据）
}

//获取栈顶的数据
STDataType STTop(ST* pst)
{
	return pst->a[pst->top - 1];
}

//判空
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

//获取数据个数
int STSize(ST* pst)
{
	assert(pst);

	//因为top指向栈顶下一个元素
	return pst->top;
}