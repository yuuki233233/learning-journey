#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Time
{
public:
	Time(int hour)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}

private:
	int _hour;
};

class Date
{
public:
	Date(int& x,int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
		,_ret(x)
		,_n(1)
		,_t(12)
	{
		//error：Time没有合适的默认构造函数可以
		//error：Date::_ref必须初始化引用
		//error：Date::_n必须初始化常量限定类型的对象
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private: //由上向下初始化
	int _year = 1;
	int _month = 1;
	int _day = 1;

	int& _ret;     //引用
	const int _n;  //const
	Time _t;	   //默认构造
};

void Test01()
{
	int i = 0;
	Date d1(i ,2025, 11, 28);
	d1.Print();
}

int main()
{
	Test01();

	return 0;
}
