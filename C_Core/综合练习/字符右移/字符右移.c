#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void str(char* ch, int len, int x)
{
	int time = x % len;//避免产生循环
	for (int i = 0; i < time; i++)
	{
		char tap = ch[0];//设置一个变量接收首字符
		int j = 0;
		for ( j = 0; j < len - 1 ; j++)
		{
			ch[j] = ch[j + 1];//交换位置
		}
		ch[j] = tap;//将最后的空位留给接受字符的变量
	}
}

int main()
{
	char ch[] = "asdfg";
	int len = strlen(ch);//求字符串长度
	str(ch, len, 6);
	printf("%s\n", ch);

	return 0;
}