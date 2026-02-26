//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////重载未全局的面临对象访问私有成员变量的问题
////有几种方法可以解决：
////1. 成员公开
////2. Date提供get函数
////3. 友元函数
////4. 重载未成员函数
//bool operator==(const Date& d1,const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//
//int main()
//{
//	Date d1(2025, 11, 26);
//	Date d2(2025, 11, 27);
//
//	//运算符重载函数可以显示调用
//	operator==(d1, d2);
//
//	//编译器会转变为operator==(d1, d2);
//	d1 == d2;
//
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	Date& operator++()
//	{
//		cout << "前置++" << endl;
//
//		return *this;
//	}
//
//	Date operator++(int)
//	{
//		Date tmp;
//		cout << "后置++" << endl;
//
//		return tmp;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//
//
//int main()
//{
//	Date d1(2025, 11, 26);
//	Date d2(2025, 11, 27);
//
//	// 运算符重载函数可以显示调用
//	d1.operator==(d2);
//
//	//编译器会转变为d1.operator==(d2);
//	d1 == d2;
//
//	//编译器会转换为d1.operator++();
//	++d1;
//
//	//编译器会转换为d1.operator++(0);
//	d1++;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	//这里必须是引用，如果直接调用会导致无穷递归调用
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Func1(Date d)
//{
//	cout << &d << endl;
//	d.Print();
//}
//
//int main()
//{
//	Date d1(2025, 11, 16);
//	d1.Print();
//
//	Func1(d1);
//
//	Date d2(d1);
//	d2.Print();
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//
//	// st2(st1)
//	Stack(const Stack& st)
//	{
//		cout << "Stack(const Stack& st)" << endl;
//
//		// 需要对_a指向资源创建同样大的资源再拷贝值
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//				sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};

//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	// Stack不显示实现拷贝构造，用自动生成的拷贝构造完成浅拷贝
//	// 会导致st1和st2里面的_a指针指向同一块资源，析构时会析构两次，程序崩溃
//	Stack st2(st1);
//
//	return 0;
//}


//void func(const Stack& st)
//{
//
//}
//
//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	func(st1);
//}


#include<iostream>
using namespace std;

class Stack
{
public:
	Stack(int n = 4)
	{
		_a = (int*)malloc(sizeof(int) * n);
		if (_a == nullptr)
		{
			perror("malloc fail");
			return;
		}
		_capacity = n;
		_pos = 0;
	}

	Stack(const Stack& st)
	{
		_a = (int*)malloc(sizeof(int) * st._capacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			return;
		}
		_capacity = st._capacity;
		_pos = st._pos;
	}

	void Push(int x)
		{
				if (_pos == _capacity)
				{
					int newcapacity = _capacity * 2;
					int* tmp = (int*)realloc(_a, newcapacity * sizeof(int));
					if (tmp == NULL)
					{
						perror("realloc fail");
						return;
					}
					_a = tmp;
					_capacity = newcapacity;
				}
				_a[_pos++] = x;
		}

	~Stack()
	{
		free(_a);
		_a = nullptr;
		_capacity = _pos = 0;
	}

private:
	int* _a;
	int _capacity;
	int _pos;
};


int main()
{
	Stack st1;
	st1.Push(1);
	st1.Push(2);

	Stack s2(st1);
	Stack s2 = st1;

	return 0;
}
