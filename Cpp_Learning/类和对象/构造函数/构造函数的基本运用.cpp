#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Date
{
public:
	// 1.无参构造函数
	Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}

	// 2.带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	////3. 全缺省构造函数
	//Date(int year = 1, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//如果留下三个构造中的第二个带参构造，第一个和第三个注释掉

	Date d1; // 调用默认构造函数
	d1.Print(); // 输出：1/1/1

	Date d2(2025, 11, 25); // 调用带参的构造函数
	d2.Print();

	//注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则编译器无法
	//区分这里是函数声明还是实例化对象

	/*Date d3(2007, 6, 18);
	d3.Print();*/

	return 0;
}