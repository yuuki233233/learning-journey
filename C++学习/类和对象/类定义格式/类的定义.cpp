#include<iostream>
using namespace std;

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	//为了区分成员变量，一般习惯是成员变量
	//会加一个特殊标识，如_ 或者 m开头
	int _year; // year_   m_year
	int _month;
	int _day;
};

int main()
{
	Date d;
	d.Init(2025, 11, 24);

	return 0;