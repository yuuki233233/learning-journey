#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"

void HPTest01()
{
	int a[] = { 4,2,8,1,5,6,9,7,3,2,23,55,232,66,222,33,7,1,66,3333,999 };
	HP hp;
	HPInit(&hp);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}

	int i = 0;
	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		//a[i++] = HPTop(&hp);
		HPPop(&hp);
	}
	printf("\n");

	
	HPDestory(&hp);
}

void HeapSort(int* a, int n)
{
	// Ωµ–Ú£¨Ω®–°∂—
	// …˝–Ú£¨Ω®¥Û∂—
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

// ∂—≈≈–Ú    O(N*logN)
// √∞≈›≈≈–Ú  O(N^2) 
void TestHeap2()
{
	HP hp;
	HPInit(&hp);
	int a[] = { 4,2,8,1,5,6,9,7,2,7,9 };
	HeapSort(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestHeap2();

	return 0;
}