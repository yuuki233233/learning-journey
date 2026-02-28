#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse(char* begin, char* end)
{
	//防止地址变了，长度也跟着改变
	int i, len = end - begin + 1;
	char ch;
	for (i = 0; i < len / 2; i++)
	{
		//拆成一份一份，交换前后每个字节
		ch = *begin;
		*begin++ = *end;
		*end-- = ch;
	}
}


int main()
{
	//手动提供内存
	char* str = (char*)calloc(128, sizeof(char));
	int i = 0;
	char ch;

	//输入：hallo world I am from shanghai
	while ((ch = getchar()) != '\n')
	{
		str[i++] = ch;
	}
	//反转成：iahgnahs morf ma I dlrow ollah
	reverse(str, str + i - 1);

	char* begin = str, * end = str;
	while (*end != '\0')
	{
		if (*end == ' ')
		{
			//输出：shanghai from am I world ollah
			reverse(begin, end - 1);
			begin = end + 1;
		}
		end++;
	}

	//输出：shanghai from am I world hallo
	printf("%s\n", str);
	//释放内存
	free(str);
	return 0;
}