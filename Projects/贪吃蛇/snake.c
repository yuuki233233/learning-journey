#define _CRT_SECURE_NO_WARNINGS
#include"Snake.h"

//坐标位置
void SetPos(short x, short y)
{
	//获得标准输出设备的句柄
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
}

//欢迎界面
//功能介绍
void WelcomeToGame()
{
	SetPos(40, 14);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(42, 20);
	system("pause");
	system("cls");

	SetPos(25, 14);
	wprintf(L"用↑.↓.←.→来控制蛇的移动，按F3加速，按F4减速\n");
	SetPos(25, 15);
	wprintf(L"加速可以得到更高的分数\n");
	SetPos(42, 20);
	system("pause");
	system("cls");

}

//绘制地图
void CreateMap()
{
	//上
	int i = 0;
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//下
	SetPos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//左
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}

	//右
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}

}

//创建蛇
void InitSnake(pSnake ps)
{
	//创建蛇的身体
	int i = 0;
	pSnakeNode cur = NULL;
	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->Next = NULL;
		//链表的位置
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;

		//头插法插入链表
		if (ps->_pSnake == NULL)//空链表
		{
			ps->_pSnake = cur;
		}
		else//非空
		{
			cur->Next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}

	cur = ps->_pSnake;
	//蛇身的打印，遍历链表
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->Next;
	}

	//设置贪吃蛇的属性
	ps->_dir = RIGHT;//默认向右
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;//毫秒
	ps->_status = OK;

}

//创建食物
void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;

	//生成x是2的倍数
	//x：2~54
	//y：1~25
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);

	//x和y的坐标不能和蛇的身体坐标冲突

	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->Next;
	}
	//创建食物的节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}

	pFood->x = x;
	pFood->y = y;
	pFood->Next = NULL;

	SetPos(x, y);//定位位置
	wprintf(L"%lc", FOOD);

	ps->_pFood = pFood;
}

void PrintHelpInfo()
{
	SetPos(64, 14);
	wprintf(L"%ls", L"不能穿墙，不能咬到自己");
	SetPos(64, 15);
	wprintf(L"%ls", L"用↑.↓.←.→来控制蛇的移动");
	SetPos(64, 16);
	wprintf(L"%ls", L"按F3加速，按F4减速");
	SetPos(64, 17);
	wprintf(L"%ls", L"按ESC退出游戏，按空格暂停游戏");

	SetPos(64, 18);
	wprintf(L"%ls", L"制作人：周某某");


}

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)

//按空格睡眠
void Pause()
{
	while (1)
	{
		Sleep(200);

		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

//判断下一个坐标是否是食物
int NextIsFood(pSnakeNode pn, pSnake ps)
{
	if (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y)
		return 1;
	else
		return 0;
}

//下一个位置为是食物，就吃掉食物
void EatFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	ps->_pFood->Next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;////

	//释放下一个位置的节点
	free(pn);
	pn = NULL;

	pSnakeNode cur = ps->_pSnake;
	//打印
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->Next;
	}
	ps->_score += ps->_food_weight;

	//重新创建食物
	CreateFood(ps);
}

//下一个位置不是食物
void NoFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	pn->Next = ps->_pSnake;
	ps->_pSnake = pn;

	pSnakeNode cur = ps->_pSnake;
	while (cur->Next->Next != NULL)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->Next;
	}

	//把最后一个节点打印成空格
	SetPos(cur->Next->x, cur->Next->y);
	printf("  ");

	//释放最后一个节点
	free(cur->Next);
	//把倒数第二个节点置为空
	cur->Next = NULL;
}

//蛇的移动(走一步)
void SnakeMove(pSnake ps)
{
	//创建一节个点，表示蛇即将到的下一个节点
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}

	//蛇头往下的位置
	switch (ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}

	//检测下一个坐标处是否是食物
	if (NextIsFood(pNextNode, ps))
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}

}

//撞到墙
void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}

//撞到自己
void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->Next;
	while (cur)
	{
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		{
			ps->_status = KILL_BY_SELF;
			break;
		}
		cur = cur->Next;
	}
}

//游戏运行逻辑
void GameRun(pSnake ps)
{
	//打印帮助信息
	PrintHelpInfo();
	do
	{
		//打印总分数和食物的分值
		SetPos(64, 10);
		printf("总分数:%d\n", ps->_score);
		SetPos(64, 11);
		//用%2d打印分数，防止加速时分数出现BUG
		printf("当前食物的分数:%2d\n", ps->_food_weight);

		//蛇不能反方向爬
		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			//暂停
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//退出
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_F3))
		{
			//减速
			if (ps->_food_weight > 2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			//加速
			if (ps->_food_weight < 18)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}

		//蛇的移动(走一步)
		SnakeMove(ps);
		Sleep(ps->_sleep_time);

		//撞到墙
		KillByWall(ps);

		//撞到自己
		KillBySelf(ps);

	} while (ps->_status == OK);
}

//结束,游戏善后的工作
void GameEnd(pSnake ps)
{
	SetPos(24, 12);
	switch (ps->_status)
	{
	case END_NORMAL:
		printf("您主动结束游戏\n");
		break;
	case KILL_BY_WALL:
		printf("您撞到了墙上，游戏结束\n");
		break;
	case KILL_BY_SELF:
		printf("您撞到了自己，游戏结束\n");
		break;
	}

	//释放链表(蛇身)
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->Next;
		free(del);
	}

}

void GameStart(pSnake ps)
{
	//窗口大小
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");

	//光标隐藏
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);

	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(houtput, &CursorInfo);

	//欢迎界面
	WelcomeToGame();

	//绘制地图
	CreateMap();

	//创建蛇
	InitSnake(ps);

	//创建食物
	CreateFood(ps);

	//运行运行
	GameRun(ps);

	//结束,游戏善后的工作
	GameEnd(ps);
}
