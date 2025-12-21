#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	bool CheckDate();

	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (!CheckDate())
		{
			cout << "非法日期";
			Print();
		}
	}

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);

		int get_month[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}

		return get_month[month];
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	// s2 = s1
	Date& operator=(const Date& d);

	// s2(s1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator<=(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator>(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);
