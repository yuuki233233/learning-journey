#define _CRT_SECURE_NO_WARNINGS
#include"11_22.h"
#include"Stack.h"

void TestPartSort1()
{
	int a[] = { 4,8,6,2,3,9,7,0,1,2 };
	int len = sizeof(a) / sizeof(a[0]);

	QuickSort1(a, 0, len - 1);
	PrintSort(a, len);
}

void TestPartSort2()
{
	int a[] = { 4,8,6,2,3,9,7,0,1,2 };
	int len = sizeof(a) / sizeof(a[0]);

	QuickSort2(a, 0, len - 1);
	PrintSort(a, len);
}

void TestPartSort3()
{
	int a[] = { 4,8,6,2,3,9,7,0,1,2 };
	int len = sizeof(a) / sizeof(a[0]);

	QuickSort3(a, 0, len - 1);
	PrintSort(a, len);
}

void TestQuickSortNonR()
{
	int a[] = { 4,8,6,2,3,9,7,0,1,2 };
	int len = sizeof(a) / sizeof(a[0]);

	QuickSortNonR(a, 0, len - 1);
	PrintSort(a, len);
}

int main()
{
	printf("快速排序(hoare版本):\n");
	TestPartSort1();
	printf("\n");

	printf("快速排序(挖坑法):\n");
	TestPartSort2();
	printf("\n");

	printf("快速排序(前后指针法):\n");
	TestPartSort3();
	printf("\n");

	printf("快速排序(非递归实现):\n");
	TestQuickSortNonR();
	printf("\n");

	return 0;
}