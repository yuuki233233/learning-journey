#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//申请5个int类型
	int* p = (int*)malloc(5 * sizeof(int));
	//判断是否为空指针
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}

	//使用申请的空间
	for (int i = 0; i < 5; i++)
	{
		*(p + i) = i + 1;
	}

	//打印
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *(p + i));
	}

	//释放空间
	free(p);

	//释放完变成野指针
	p = NULL;

	return 0;
}
