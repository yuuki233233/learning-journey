#define _CRT_SECURE_NO_WARNINGS
#include"date.h"

bool Date::CheckDate()
{
	if (_month < 1 || _month > 12
		|| _day < 1 || _day > GetMonthDay(_year, _month))
	{
		return false;
	}
	else
	{
		return true;
	}
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day > d._day;
		}
	}
	return false;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	if (day < 0)
		return *this -= (-day);

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;

		if (_month == 13)
		{
			_month = 1;
			++_year;
		}
	}

	return *this;
}

Date Date::operator+(int day)
{
	*this = *this + day;
	return *this;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
		return *this += (-day);

	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day)
{
	*this = *this - day;
	return *this;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "year/" << d._month << "month/" << d._day << "day" << endl;

	return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "请输入年月日:>";
	in >> d._year >> d._month >> d._day;

	return in;
}