#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	bool check_date()
	{
		if (_month > 0 && _month < 13)
		{
			if()
			return true;
		}
	}

	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (!check_date())
		{
			cout << "非法日期";
			Print();
		}
	}

	int git_month_date(int year, int month)
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

private:
	int _year;
	int _month;
	int _day;
};

void test_date01();