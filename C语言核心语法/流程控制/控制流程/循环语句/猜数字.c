#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void menu()
{
	printf("**********************************\n");
	printf("***        1. play             ***\n");
	printf("***        0. exit             ***\n");
	printf("**********************************\n");

}

void game()
{
	int gurss = 0;
	int ret = rand() % 100 + 1;
	int num = 0;

	while (1)
	{
		num++;
		printf("请输入要猜的数:>");
		scanf("%d", &gurss);

		if (gurss > ret)
		{
			printf("猜大了\n");
		}
		else if (gurss < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜您第%d猜对了\n",num);
			break;
		}
	}

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
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
			printf("选择错误,重新选择\n");
			break;
		}
	} while (input);
	return 0;
}