#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	//-----------------------------------------------
	//这里必须是引用，如果直接调用会导致无穷递归调用
	//d2(d1)，加const是为了保护d不被修改
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//-----------------------------------------------

private:
	int _year;
	int _month;
	int _day;
};

//void Func1(Date d)
//这里把Date d--->Date& d是为了减少创建空间，
//调用自己提高效率
void Func1(Date& d)
{
	cout << &d << endl;
	d.Print();
}

int main()
{
	Date d1(2025, 11, 16);
	d1.Print();

	Func1(d1);

	Date d2(d1);
	d2.Print();

	return 0;
}