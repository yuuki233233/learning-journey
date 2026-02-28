#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>//strstr头文件

int main()
{
	char arr1[] = "yuuki@Outlook.com";
	char s[100] = { 0 };
	strcpy(s, arr1);//拷贝同一个需要查找的字符串

	const char* arr2 = "@.";//查找需要去除的字符
	char* ret = NULL;//设一个空指针接受strtok返回的字符串

	for (ret = strtok(s, arr2); ret != NULL; ret = strtok(NULL, arr2))//后面需要空指针接收
	{
		printf("%s\n", ret);
	}
	return 0;
}