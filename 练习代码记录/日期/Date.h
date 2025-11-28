#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

class Date
{
	//友元函数
	friend ostream& operator<<(ostream& out, const Date& d);

	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int year = 1990, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

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

	inline int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);

		static int MontDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
		if ((month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)))
		{
			return 29;
		}
		return MontDayArray[month];
	}

	 bool CheckDate();
	
	 bool operator<(const Date & d);
	 bool operator<=(const Date & d);
	 bool operator>(const Date & d);
	 bool operator>=(const Date & d);
	 bool operator==(const Date & d);
	 bool operator!=(const Date & d);

	 Date& operator+=(int day);
	 Date operator+(int day);

	 Date& operator-=(int day);
	 Date operator-(int day);

	 Date operator++(int);
	 Date& operator++();

	 Date operator--(int);
	 Date& operator--();

	 int operator-(const Date& d);

	 //this接收d、io流只能在第二位
	 //ostream& operator<<(ostream& out);

private:
	int _year;
	int _month;
	int _day;
};

//用全局，可将this做为io流，d在第二位
ostream& operator<<(ostream& out, const Date& d);

istream& operator>>(istream& in, Date& d);