#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int is_leap_year(int x)
{
	if (((x % 4 == 0) && (x % 100 != 0)) || x % 400 == 0)
		return 1;
	else
		return 0;
}
int get_days_for_month(int x,int y)
{
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = days[y];

	if(is_leap_year(x) && y == 2)
		day += 1;
	return day;
}
int main()
{
	int year = 0;
	int month = 0;
	printf("请输入年份和月份:>");
	scanf("%d%d", &year, &month);

	int day = get_days_for_month(year,month);
	printf("%d年%d月共有%d天",year, month, day);
	return 0;
}