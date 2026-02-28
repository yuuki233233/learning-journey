#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort1(int* a, int left, int right);
void QuickSort2(int* a, int left, int right);
void QuickSort3(int* a, int left, int right);


// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);

void PrintSort(int* a, int len);
