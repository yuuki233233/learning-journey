#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int num = 0;
	int a = 0;
	printf("输出个正整数: ");
	scanf("%d", &num);

	while (num > 0) {
		int end = num % 10;
		printf("%d", end);
	    a += end;
		num = num / 10;
	}
	printf("\n");
	printf("逆序相加值为: ");
	printf("%d", a);
	return 0;
}