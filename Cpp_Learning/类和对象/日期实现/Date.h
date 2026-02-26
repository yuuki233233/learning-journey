#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

class Date
{
public:
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

	//判断是否非法日期
	bool CheckDate();

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);

		int MonthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}

		return MonthDayArray[month];
	}


	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date& operator-=(int day);
	Date operator-(int day);
	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator--();
	Date operator--(int);
	Date& operator++();
	Date operator++(int);

	int operator-(const Date& d);

	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
private:
	int _year = 1900;
	int _month = 1;
	int _day = 1;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);