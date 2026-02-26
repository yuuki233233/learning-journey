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

	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	/*~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}*/

private:
	int _year;
	int _month;
	int _day;
};

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