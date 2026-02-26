#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

class Date
{
	//友元函数(可将流放入this位)
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	//构造函数(可省略创建Init)
	Date(int year = 1990, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		//当日期不正确时，报错并打印出非法日期
		if (!CheckDate())
		{
			cout << "非法日期";
			Print();
		}
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//最常调用的函数，应放到类里面实现。编译器会自动加上内联函数(inline)提高效率
	inline int GetMonthDay(int year, int month)
	{
		//非法月份
		assert(month > 0 && month < 13);

		//放回每个月的总天数(用数组实现，也要判断年份是否为闰年时)
		static int MontDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
		if ((month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)))
		{
			return 29;
		}
		return MontDayArray[month];
	}

	//判断是否非法日期
	 bool CheckDate();
	
	 //用运算符重载来比较两日期
	 //在类中，this指针指向第一类，第二类在( )中写入
	 bool operator<(const Date& d);
	 bool operator<=(const Date& d);
	 bool operator>(const Date& d);
	 bool operator>=(const Date& d);
	 bool operator==(const Date& d);
	 bool operator!=(const Date& d);

	 //运用引用时，减少拷贝，提高效率
	 Date& operator+=(int day);
	 Date operator+(int day);

	 Date& operator-=(int day);
	 Date operator-(int day);

	 //前置++()中为空
	 //后置++需要()中加上int
	 Date operator++(int);
	 Date& operator++();

	 Date operator--(int);
	 Date& operator--();

	 //两日期相减，返回的是整形
	 int operator-(const Date& d);

	 //this接收d、io流只能在第二位
	 //ostream& operator<<(ostream& out);

private:
	//内置类型没有申请空间，不需要析构函数
	int _year;
	int _month;
	int _day;
};

//用全局，可将this做为io流，d在第二位
ostream& operator<<(ostream& out, const Date& d);

istream& operator>>(istream& in, Date& d);