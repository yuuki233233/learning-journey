#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

int main()
{
	//申请内存
	int* p = (int*)calloc(10, sizeof(int));
	//判断是否为空指针
	if (NULL != p)
	{
		int i = 0;
		//打印
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//释放内存
	free(p);
	//p为野指针，让p指向空指针
	p = NULL;

	return 0;
}