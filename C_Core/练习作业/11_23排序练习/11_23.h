#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void PrintSort(int* a, int n);

// 归并排序递归实现
void _MergeSort(int* a, int* tmp, int left, int right);
void MergeSort(int* a, int n);

// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n);