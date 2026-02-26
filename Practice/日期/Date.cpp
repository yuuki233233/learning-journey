#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"

//类外定义，需要运用到命名空间的知识
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

Date& Date::operator+=(int day)
{
	//实现日期改变
	if (day < 0)
	{
		return *this -= (-day);
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}

	_day -= day;
	while(_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;

	return tmp;
}

//Date& Date::operator-=(int day)
//{
//	*this = *this - day;
//
//	return *this;
//}
//
//Date Date::operator-(int day)
//{
//	Date tmp = *this;
//	
//	tmp._day -= day;
//	while (tmp._day <= 0)
//	{
//		tmp._month--;
//		if (tmp._month == 0)
//		{
//			tmp._year--;
//			tmp._month = 12;
//		}
//		tmp._day += GetMonthDay(tmp._year, tmp._month);
//	}
//
//	return tmp;
//}

//d2 < d1
bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day < d._day;
		}
	}

	return false;
}

//d2 <= d1
bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}

//d2 > d1
bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}

//d2 >= d1
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

//d2 == d1
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//d2 != d1
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// d1 - d2
int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;
}


//ostream& Date::operator<<(ostream& out)
//{
//	out << _year << "年" << _month << "月" << _day << "日" << endl;
//	return out;
//}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;

	return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "请输入年月日:>";
	in >> d._year >> d._month >> d._day;

	return in;
}