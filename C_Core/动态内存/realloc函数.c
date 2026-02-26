#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//申请内存
	int* p = (int*)malloc(5 * sizeof(int));
	//赋值
	for (int i = 0; i < 5; i++)
	{
		*(p + i) = i + 1;
	}

	//修改内存大小
	int* ptr = (int*)realloc(p, 40);
	//错误写法：
	//p = (int*)realloc(p,40);
	//怕返回空指针，丢失旧数据

	//判断是否为空指针
	if (ptr != NULL)
	{
		//若不是把ptr的地址赋值给p
		p = ptr;
		//输入数据
		for (int i = 5; i < 10; i++)
		{
			*(p + i) = i + 1;
		}
		//打印数据
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", p[i]);
		}
		//使用完释放空间
		free(p);
		//释放完p变为野指针，让p指向空指针
		p = NULL;
	}
	//若为空指针，则报错
	else
	{
		perror("realloc");
		return 1;
	}
	return 0;
}