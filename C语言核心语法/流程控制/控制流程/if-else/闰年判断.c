#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int year = 0;

	do {
		printf("请输入年份,输入-1则退出循环: ");

		if (scanf("%d", &year) != 1) {
			printf("输入无效,请输入有效年份:\n");
			while (getchar() != '\n');
			continue;
		}

		if (year == -1) {
			printf("程序结束\n");
			break;
		}

		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			printf("此年为闰年\n");
		}
		else {
			printf("不是闰年\n");
		}
	} while (1);

	return 0;
}