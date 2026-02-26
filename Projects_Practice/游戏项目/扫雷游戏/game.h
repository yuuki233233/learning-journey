#pragma once
#include<stdio.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#define lei 10

//初始化
void InitBorad(char arr[ROWS][COLS], int rows, int cols, int set);

//打印
void InputBorad(char arr[ROWS][COLS], int row, int col);

//设置雷区
void SetMine(char arr[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);