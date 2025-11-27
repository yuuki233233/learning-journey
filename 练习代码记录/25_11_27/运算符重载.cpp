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

	//private:
	int _year;
	int _month;
	int _day;
};


//重载未全局的面临对象访问私有成员变量的问题
bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}


int main()
{
	Date d1(2025, 11, 26);
	Date d2(2025, 11, 27);

	//运算符重载函数可以显示调用
	operator==(d1, d2);

	//编译器会转变为operator==(d1, d2);
	d1 == d2;

	return 0;
}