#define _CRT_SECURE_NO_WARNINGS
#include"Snake.h"
#include<locale.h>

void test()
{
	int ch = 0;
	do
	{
		//每一次清理一次屏幕信息
		system("cls");

		//创建
		Snake snake = { 0 };

		//初始化
		GameStart(&snake);

		//运行
		GameRun(&snake);

		//结束
		GameEnd(&snake);
		SetPos(0, 27);

		SetPos(20, 15);
		printf("再来一局吗?(Y/N):");
		ch = getchar();
		getchar() != '\n';//清理Y

	} while (ch == 'Y' || ch == 'y');
	SetPos(0, 27);
}

int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));

	test();
	return 0;
}