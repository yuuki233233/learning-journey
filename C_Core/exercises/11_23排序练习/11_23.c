#define _CRT_SECURE_NO_WARNINGS
#include"11_23.h"

void TestMergeSort()
{
	int a1[] = { 3,7,5,8,0,7,6,1,3,9,3 };
	int len = sizeof(a1) / sizeof(a1[0]);

	MergeSort(a1, len);
	PrintSort(a1, len);
}

void TestMergeSortNonR()
{
	int a2[] = { 4,6,8,1,3,9,7,0,3,9,5 };
	int len = sizeof(a2) / sizeof(a2[0]);

	MergeSort(a2, len);
	PrintSort(a2, len);
}

void TestCountSort()
{
	int a3[] = { 3,6,9,5,1,5,0,9,6,3,2 };
	int len = sizeof(a3) / sizeof(a3[0]);

	CountSort(a3, len);
	PrintSort(a3, len);
}

int main()
{
	TestMergeSort();
	TestMergeSortNonR();
	TestCountSort();
	return 0;
}