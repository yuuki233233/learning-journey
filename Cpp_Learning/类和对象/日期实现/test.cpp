#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"

void Test01()
{
	Date d1(2025, 11, 30);
	d1.Print();

	d1 -= 100;
	d1.Print();
}

void Test02()
{
	Date d1(2007, 6, 18);
	Date ret1 = d1++;
	ret1.Print();
	d1.Print();

	Date d2(2025, 11, 30);
	Date ret2 = ++d2;
	ret2.Print();
	d2.Print();
}

void Test03()
{
	Date d1(2025, 11, 30);
	d1 += -100;
	d1.Print();

	d1 -= -100;
	d1.Print();
}

void Test04()
{
	Date d1(2034, 10, 1);
	Date d2(2024, 6, 30);

	cout << d1 - d2 << endl;
}

void Test05()
{
	Date d1(2025, 11, 27);
	Date d2(2025, 11, 28);
	//倒反天罡(在成员函数中，this指针是d1，而out却在第二个中)
	//d1 << cout;
	//d1.operator<<(cout);

	//返回值接收流，可以输出多个
	cout << d1 << d2;
}

void Test06()
{
	Date d1;
	Date d2;

	cin >> d1 >> d2;
	cout << d1 << d2;

	cout << d1 - d2 << endl;
}

int main()
{
	Test01();

	return 0;
}