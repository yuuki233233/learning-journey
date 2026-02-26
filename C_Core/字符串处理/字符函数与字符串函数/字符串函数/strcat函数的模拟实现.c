#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

//返回值为char*，接收类型也为char*
char* my_strcat(char* dest, const char* src)//const保护源数据，防止被修改
{
	assert(dest && src);
	//保存dest首地址
	char* ret = dest;
	//1.找目标空间\0
	while (*dest != '\0')
		dest++;
	//2.拷贝
	while (*dest++ = *src++)
		;//空语句
	return ret;//函数的返回值为数组首元素，这样数组才能往下打印完全
}
int main()
{
	char arr1[20] = "hallo ";//追加空间要足够大
	char arr2[] = "world";

	char* s = my_strcat(arr1, arr2);//接收类型为char*
	printf("%s\n", arr1);
	printf("%s\n", s);
	printf("%s\n", my_strcat(arr1, arr2));//arr1已经为hallo world再与arr2进行合并，变为hallo worldworld

	return 0;
}