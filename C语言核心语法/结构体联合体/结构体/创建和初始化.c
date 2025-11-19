#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct book
{
	char name[20];
	char author[20];
	float price;
	char id[13];
};

int main()
{
	//按照结构体成员的顺序初始化
	struct book b1 = { "PengGe_C Yuyan","PengGe",49.9, "QWE"};
	//单个打印
	printf("%s ", b1.name);
	printf("%s ", b1.author);
	printf("%.1f ", b1.price);
	printf("%s ", b1.id);

	printf("\n");
	//一次性打印
	printf("%s %s %.1f %s\n", b1.name, b1.author, b1.price, b1.id);

	//按照指定的顺序初始化
	struct book b2 = { .id = "RTY", .price = 8.8, .author = "PengGe", .name = "PengGe_C" };

	//一次性打印
	printf("%s %s %.1f %s\n", b2.name, b2.author, b2.price, b2.id);

	return 0;
}