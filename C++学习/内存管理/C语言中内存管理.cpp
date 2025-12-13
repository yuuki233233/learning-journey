#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void test()
{
    int* p1 = (int*)malloc(4 * sizeof(int));  // 分配空间，不初始化
    int* p2 = (int*)calloc(4, sizeof(int));   // 分配空间并初始化为0
    int* p3 = (int*)realloc(p2, 10 * sizeof(int)); // 重新分配空间

    free(p1);
    free(p3);  // realloc后只需释放新指针
}