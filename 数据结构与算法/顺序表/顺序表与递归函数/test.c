#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"


void menu()
{
	printf("***********************************\n");
	printf("**** 1.头插  2.尾插  3.随机插入 ****\n");
	printf("**** 4.头删  5.尾删  6.随机删除 ****\n");
	printf("**** 0.退出                    ***\n");
	printf("**********************************\n");
}

void SeqListTest()
{
	SL sl;
	CaqListInit(&sl);

	// 定义函数指针，指向具体的操作函数
	SLPushFrontFunc pushFront = SLPushFront;
	SLPushBackFunc pushBack = SLPushBack;
	SLPushPosFunc pushPos = SLPush;
	SLPopFrontFunc popFront = SLPopFront;
	SLPopBackFunc popBack = SLPopBack;
	SLPopPosFunc popPos = SLPop;

	int input = 0;
	do
	{
		menu();

		scanf("%d", &input);
		ListDateType val = 0;
		int pos = 0;
		switch (input)
		{
		case 0:
			printf("退出顺序表\n");
			break;
		case 1:
			printf("请输入要添加的元素：");
			scanf("%d", &val);
			pushFront(&sl, val); // 回调头插函数
			break;
		case 2:
			printf("请输入要添加的元素：");
			scanf("%d", &val);
			pushBack(&sl, val); // 回调尾插函数
			break;
		case 3:
			printf("请输入位置和元素（位置 元素）：");
			scanf("%d %d", &pos, &val);
			pushPos(&sl, pos, val); // 回调指定位置插入函数
			break;
		case 4:
			popFront(&sl); // 回调头删函数
			break;
		case 5:
			popBack(&sl); // 回调尾删函数
			break;
		case 6:
			printf("请输入要删除的位置：");
			scanf("%d", &pos);
			popPos(&sl, pos); // 回调指定位置删除函数
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
		if (input != 0)
		{
			SLPrint(sl); // 每次操作后打印顺序表
		}
	} while (input);

	SLDestory(&sl);

}

int main()
{
	SeqListTest();
	return 0;
}