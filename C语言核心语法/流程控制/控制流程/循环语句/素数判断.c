#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int main() {
	int num = 0;
	printf("请输入大于1的整数: ");
	scanf("%d", &num);

	if (num <= 1) {
		printf("输入错误!请重新输入大于1的整数\n");
		return 1;
	}

	if (num == 2) {
		printf("是素数\n");
		return 0;
	}

	if (num % 2 == 0) {
		printf("不是素数\n");
		return 0;
	}

	bool a = true;
	for (int i = 3; i * i < num; i+=2) {
		if (num % i == 0) {
			a = false;
			break;
		}
	}

	if (a) {
		printf("是素数\n");
	}
	else {
		printf("不是素数\n");
	}
	return 0;
}