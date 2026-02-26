#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdlib.h>
#include"game.h"

void sta()
{
	printf("*********************\n");
	printf("****   1. play   ****\n");
	printf("****   0. Exit   ****\n");
	printf("*********************\n");
}

void game()
{
	//设置游戏
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化游戏
	InitBorad(mine, ROWS, COLS, '0');
	InitBorad(show, ROWS, COLS, '*');

	//设置雷区
	SetMine(mine, ROW, COL);

	//打印游戏
	//InputBorad(mine, ROW, COL);
	InputBorad(show, ROW, COL);

	//查找雷区
	FindMine(mine, show, ROW, COL);
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		sta();
		printf("请选择选项:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}