#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	//释放空间，str指向野指针，并不是空指针
	free(str);
	//应该加：str = NULL;
	if (str != NULL)
	{
		//非法访问内存
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();
	return 0;
}