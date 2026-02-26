#define _CRT_SECURE_NO_WARNINGS
#include"date.h"

void test_date01()
{
	Date d1(2025, 12, 10);
	d1.Print();

	Date d2(2007, 6, 18);
	d2.Print();

	//运算符重载
	d1 = d2;
	d1.Print();

	//拷贝构造
	Date d3 = d1;
	d3.Print();
}
	
void test_date02()
{
	Date d1(2025, 12, 10);
	Date d2(2025, 12, 10);

	d1 += 100;
	d1.Print();

	d2 -= 100;
	d2.Print();
}

void test_date03()
{
	Date d1(2025, 12, 10);
	Date d2(2007, 6, 18);

	cout << d1 << d2;

	cin >> d1 >> d2;
	cout << d1 << d2;
}

int main()
{
	//test_date01();
	//test_date02();
	test_date03();

	return 0;
}