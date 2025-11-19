#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>//使用assert包含的头文件

void* my_memcpy(void* arr2, void* arr1, int num)
{
	//判断是否为空指针
	assert(arr1 && arr2);

	void* n = arr2;
	//交换40个字节，交换1次就减1个
	while (num--)
	{
		//强转成char*类型，因为只占一个字节
		//让arr2的单字节=arr1的单字节
		*(char*)arr2 = *(char*)arr1;

		//交换后(在char*类型的前提下)都往后移一个字节
		arr1 = (char*)arr1 + 1;
		arr2 = (char*)arr2 + 1;
	}
	return n;
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = { 0 };

	void* ret = my_memcpy(arr2, arr1, 10*sizeof(int));//传入实参

	//打印数组arr2
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}