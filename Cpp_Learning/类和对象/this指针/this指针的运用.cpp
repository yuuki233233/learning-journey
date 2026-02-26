#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Date
{
public:
	// void Init(Date* const this, int year, int month, int day)
	void Init(int year, int month, int day)
	{
		//类里的函数里面加指针this解引用，两种都可行
		this->_year = year;
		this->_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	//这里只是声明，没有开辟空间
	int _year;
	int _month;
	int _day;
};

int main()
{
	// Date类实例化出对象d1和d2
	Date d1;
	Date d2;

	// d1.Init(&d1, 2024, 3, 31);
	d1.Init(2025, 5, 20);
	d1.Print();

	d2.Init(2026, 5, 20);
	d2.Print();

	return 0;
}