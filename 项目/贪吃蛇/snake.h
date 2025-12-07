#pragma once

#include<stdio.h>
#include<stdbool.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

#define POS_X 24
#define POS_Y 5

#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'

//方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//状态
enum GAME_STATUS
{
	OK,//正常
	KILL_BY_WALL,//撞墙
	KILL_BY_SELF,//撞自己
	END_NORMAL//正常退出
};

//节点
typedef struct SnakeNode
{
	//坐标
	int x;
	int y;
	//指向下一个节点的指针
	struct SnakeNode* Next;
}SnakeNode, * pSnakeNode;

//贪吃蛇
typedef struct Sanke
{
	pSnakeNode _pSnake;//指向蛇头的头

	pSnakeNode _pFood;//指向食物节点的指针

	enum DIRECTION _dir;//方向

	enum GAME_STATUS _status;//游戏的状态

	int _food_weight;//食物的分数

	int _score;//总分数

	int _sleep_time;//休息时间
}Snake, * pSnake;

//坐标位置
void SetPos(short x, short y);

//欢迎界面
void GameStart(pSnake ps);

//绘制地图
void WelcomeToGame();

//创建蛇
void InitSnake(pSnake ps);

//创建食物
void CreateFood(pSnake ps);

//游戏运行逻辑
void GameRun(pSnake ps);

//蛇的移动(走一步)
void SnakeMove(pSnake ps);

//判断下一个坐标是否是食物
int NextIsFood(pSnakeNode pn, pSnake ps);

//下一个位置为是食物，就吃掉食物
void EatFood(pSnakeNode pn, pSnake ps);

//下一个位置不是食物
void NoFood(pSnakeNode pn, pSnake ps);

//撞到墙
void KillByWall(pSnake ps);

//撞到自己
void KillBySelf(pSnake ps);

//结束,游戏善后的工作
void GameEnd(pSnake ps);