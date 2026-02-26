#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


	int main()
	{
		do{
		printf("请输入您的分数(0 ~ 100)之间,并查询评估,输入-1退出:");
		int score = 0;
		if (scanf("%d", &score) != 1)
		{
			printf("错误:请输入有效数字!\n");
			return 1;
		}

		if (-1 == score) break;

		if (score >= 90 && score <= 100)
		{
			printf("您的评估为优秀\n");
		}
		else if (score >= 80 && score < 90)
		{
			printf("您的评估为良好\n");
		}
		else if (score >= 70 && score < 80)
		{
			printf("您的评估为中等\n");
		}
		else if (score >= 60 && score < 70)
		{
			printf("您的评估为及格\n");
		}
		else if (score < 60)
		{
			printf("您的评估为不及格\n");
		}
		else
		{
			printf("您输入的分数无效\n");
		}
	}while(1);
	return 0;
}