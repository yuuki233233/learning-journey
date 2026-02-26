#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int dayOfWeek = 0;
	do {
		printf("请输入今天是星期几,输入-1退出: ");
		if (scanf("%d", &dayOfWeek) != 1) {
			printf("请输入有效数字\n");
			while (getchar() != '\n') {
				continue;
			}
		}

		if (dayOfWeek == -1)break;

		switch (dayOfWeek) {
		case 1: printf("工作日开始,加油!\n"); break;
		case 2: printf("工作学习日\n"); break;
		case 3: printf("一周过半啦!\n"); break;
		case 4: printf("周末快来了\n"); break;
		case 5: printf("明天就周末啦!\n"); break;
		case 6: printf("周末愉快!\n"); break;
		case 7: printf("休息日,准备新的一周\n"); break;
		default:printf("请输入有效星期\n");
		}
	} while (1);

	return 0;
}