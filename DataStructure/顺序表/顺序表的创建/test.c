#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

#if 0
void SLTest01()
{
	SL sl;
	//初始化
	SLInit(&sl);

	//尾插
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	//打印
	SLPrint(sl);//1234

	//头插
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	//打印
	SLPrint(sl);//561234



	//删除最后一个元素
	SLPopBack(&sl);
	SLPrint(sl);//56123

	//删除第一个元素
	SLPopFront(&sl);
	SLPrint(sl);//6123

	//销毁地址
	SLDestory(&sl);
}
#endif

void SLTest02()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(sl);//1 2 3 4

	//测试指定位置之前插入数据
	SLInsert(&sl, 0, 99);
	SLPrint(sl);//99 1 2 3 4

	SLInsert(&sl, sl.size, 88);
	SLPrint(sl);//99 1 2 3 4 88 

	SLInsert(&sl, 2, 77);
	SLPrint(sl);//99 1 77 2 3 4 88

	//测试指定位置删除
	SLErase(&sl, 0);
	SLPrint(sl);//1 77 2 3 4 88

	//测试顺序表的查找
	int find = SLFind(&sl, 4);
	if (find < 0)
	{
		printf("没有找到!\n");
	}
	else
	{
		printf("找到了！下标为%d!!", find);
	}

	SLDestory(&sl);
}

int main()
{
	//SLTest01();
	SLTest02();
	return 0;
}