#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *init()
{
	//char str[32] = { 0 };
	// 
	//ÉêÇëÄÚ´æ
	char* str = (char*)malloc(128);
	return str;
}

int main()
{
	char* s = init();
	strcpy(s, "hallo");
	printf("%s", s);
	//ÊÍ·ÅÄÚ´æ
	free(s);
	return 0;
}