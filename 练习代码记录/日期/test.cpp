#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"

void Test01()
{
	Date d1(2025, 11, 28);
	d1.Print();

	Date d2 = d1 - 100;
	d2.Print();
}

void Test02()
{
	Date d1(2024, 7, 13);
	Date ret1 = d1++;
	ret1.Print();
	d1.Print();

	Date d2(2024, 7, 13);
	Date ret2 = ++d2;
	ret2.Print();
	d2.Print();
}

void Test03()
{
	Date d1(2024, 7, 12);
	d1 += -100;
	d1.Print();

	d1 -= -100;
	d1.Print();
}

void Test04()
{
	Date d1(2034, 10, 1);
	Date d2(2024, 6, 31);

	cout << d1 - d2 << endl;
}

int main()
{
	Test04();

	return 0;
}