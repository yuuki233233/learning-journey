#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>	

//通过地址互换改变a与b的值	
void swap(int* x, int* y)
{
	int tamp = *x;
	*x = *y;
	*y = tamp;
}

int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("交换前的值a = %d , b = %d\n", a, b);

	swap(&a, &b);

	printf("交换后的值a = %d , b = %d\n", a, b);

	return 0;
}
