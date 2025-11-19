#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>//strstr头文件

char* my_strstr(char* str1, char* str2)
{
	const char* s1 = NULL;
	const char* s2 = NULL;//将s1与s2设为空指针
	const char* cur = str1;//设个cur指针指向首地址，方便回到上次查找str1的地方

	if (*str2 == '\0')//极端情况，str2没有字符
	{
		return (char*)str1;//则直接返回str1的首地址
	}

	while (*cur)//当*cur为'\0'退出循环,'\0'的ASCLL码值为0
	{
		s1 = cur;
		s2 = str2;//把s1、s2附上首元素地址

		while (*s1 != '\0' && *s2 != '0' && *s1 == *s2)
		{
			s1++;
			s2++;//查找两元素是否相同
			return (char*)cur;//查找到最后都相同时，返回
		}
		cur++;//条件不成立时，使cur向--→移一位，继续找一遍
	}
	return NULL;//条件不成立，返回空指针

}

int main()
{
	char arr1[] = "abcdefabcdef";
	char arr2[] = "cdef";
	char* ret = my_strstr(arr1, arr2);//传入实参
	if (ret == NULL)
		printf("没找到\n");
	else
		printf("%s\n", ret);
	return 0;
}