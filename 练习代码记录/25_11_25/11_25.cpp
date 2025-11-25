//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
////C++升级struct升级成了类
////1、类里面可以定义函数
////2、struct名称就可以代表类型
//
////C++兼容C中struct的用法
//typedef struct ListNodeC
//{
//	struct ListNOdeC* next;
//	int val;
//}LTNode;
//
////C++中不再需要typedef，ListNodeCPP就可以代表类型
//struct ListNodeCPP
//{
//	//C++中，struct可以定义函数
//	void Init(int x)
//	{
//		next = nullptr;
//		val = x;
//	}
//
//	//不需要用struct ListNodeCPP
//	ListNodeCPP* next;
//	int val;
//};
//
//int main()
//{
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Stack
//{
//public:
//	//成员函数
//	void Init(int n = 4);
//
//private:
//	//成员变量
//	int* array;
//	size_t capacity;
//	size_t top;
//};
//
////声明和定义分离，需要指定类域
//void Stack::Init(int n)
//{
//	array = (int*)malloc(sizeof(int) * n);
//	if (nullptr == array)
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	capacity = n;
//	top = 0;
//}
//
//int main()
//{
//	Stack st;
//	st.Init();
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
//	void Init(int year, int month, int day)
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
//private:
//	//这里只是声明，没有开辟空间
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// Date类实例化出对象d1和d2
//	Date d1;
//	Date d2;
//
//	d1.Init(2025, 5, 20);
//	d1.Print();
//
//	d2.Init(2026, 5, 20);
//	d2.Print();
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class A
//{
//public:
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//
//private:
//	char _ch;
//	int _i;
//};
//
//class B
//{
//	void Print() {};
//};
//
//class C
//{ };
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//
//	cout << sizeof(a) << endl; //8
//	cout << sizeof(b) << endl; //1
// 	cout << sizeof(c) << endl; //1
//
//	return 0;
//}



//class Date
//{
//public:
//	// void Init(Date* const this, int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		//类里的函数里面加指针this解引用，两种都可行
//		this->_year = year;
//		this->_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	//这里只是声明，没有开辟空间
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// Date类实例化出对象d1和d2
//	Date d1;
//	Date d2;
//
//	// d1.Init(&d1, 2024, 3, 31);
//	d1.Init(2025, 5, 20);
//	d1.Print();
//
//	d2.Init(2026, 5, 20);
//	d2.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Print();  //A::Print()
//
//	return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//		cout << _a << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//
//	return 0;
//}

//class Date
//{
//public:
//	// 1.无参构造函数
//	Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//
//	// 2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	////3. 全缺省构造函数
//	//Date(int year = 1, int month = 1, int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//如果留下三个构造中的第二个带参构造，第一个和第三个注释掉
//
//	Date d1; // 调用默认构造函数
//	d1.Print(); // 输出：1/1/1
//
//	Date d2(2025, 11, 25); // 调用带参的构造函数
//	d2.Print();
//
//	//注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则编译器无法
//	//区分这里是函数声明还是实例化对象
//
//	/*Date d3(2007, 6, 18);
//	d3.Print();*/
//
//	return 0;
//}

typedef int STDataType;
class Stack
{
public:
	Stack(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)
		{
			perror("malloc fail");
			return;
		}

		_capacity = n;
		_top = 0;
	}

private:
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};

// 两个Stack实现队列
class MyQueue
{
public:
	//编译器默认生成MyQueue的构造函数调用了Stack的构造，完成了两个成员的初始化

private:
	Stack pushst;
	Stack popst;
};

int main()
{
	MyQueue mq;

	return 0;
}