#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>//包含头文件

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//内存足够大
	int arr2[20] = { 0 };
	//拷贝内存,最右边数字表示字节
	memcpy(arr2, arr1, 10*sizeof(int));
	//打印数组arr2
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", arr2[i]);
	}

	return 0;
}