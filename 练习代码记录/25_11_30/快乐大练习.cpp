//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{ }
//
//	void Print()const
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
//void Test01()
//{
//	const Date d1(2025, 11, 30);
//	d1.Print();
//
//}
//
//int main()
//{
//	Test01();
//
//
//	return 0;
//}
//

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	// 构造函数explicit就不再⽀持隐式类型转换
//	// explicit A(int a1)
//	A(int a1)
//		:_a1(a1)
//	{}
//	//explicit A(int a1, int a2)
//	A(int a1, int a2)
//		:_a1(a1)
//		,_a2(a2)
//	{}
//
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//	int Get() const
//	{
//		return _a1 + _a2;
//	}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//public:
//	B(const A& a)
//		:_b(a.Get())
//	{}
//
//private:
//	int _b = 0;
//};
//
//int main()
//{
//	// 1构造⼀个A的临时对象，再⽤这个临时对象拷贝构造aa3
//	// 编译器遇到连续构造+拷贝构造->优化为直接构造
//	A aa1 = 1;
//	aa1.Print();
//
//	const A& aa2 = 1;
//
//	// C++11之后才⽀持多参数转化
//	A aa3 = { 2,2 };
//
//	// aa3隐式类型转换为b对象
//	// 原理跟上⾯类似
//	B b = aa3;
//	const B& rb = aa3;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	// 构造函数explicit就不再⽀持隐式类型转换
//	// explicit A(int a1)
//	A(int a1 = 1)
//	{
//		_a1 = a1;
//	}
//
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//	//explicit A(int a1, int a2)
//	A(int a1, int a2)
//		:_a1(a1)
//		,_a2(a2)
//	{}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class Stack
//{
//public:
//	//原本A a3 = 3, Push(a3)
//	//简化成Push(3)
//	void Push(const A& aa)
//	{
//		//...
//	}
//
//private:
//	A* _arr[10];
//	int _top;
//};
//
//int main()
//{
//	A aa1(1);
//	aa1.Print();
//
//	// 2构造⼀个A的临时对象，再⽤这个临时对象拷贝构造aa2
//	// 编译器遇到连续构造+拷贝构造->优化为直接构造
//	A aa2 = 2;
//	aa2.Print();
//
//	A& rra1 = aa2;
//	const A& raa2 = 2;//类型转换(具有常性)
//
//	int i = 1;
//	double d = i;
//	const double& rd = i;
//
//	Stack st;
//
//	//效果一样
//	//------------------
//	A aa3(3);
//	st.Push(aa3);
//	//------------------
//	st.Push(3);
//	//------------------.
//
//
//	//多参数
//	A aa5 = { 1,1 };
//	st.Push(aa5);
//	st.Push({ 3, 3 });
//
//	const A& aa6 = { 2,2 };
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A()
//	{
//		_scount++;
//	}
//
//	A(const A& a)
//	{
//		_scount++;
//	}
//
//	~A()
//	{
//		_scount--;
//	}
//
//	static int GetACount()
//	{
//		return _scount;
//	}
//
//	static int M()
//	{
//		//_a;
//	}
//
//	void Print()
//	{
//		cout << A::GetACount() << endl;
//		cout << _scount << endl;
//	}
//
//private:
//	static int _scount;
//	int _a;
//};
//
////类外初始化
//int A::_scount = 0;
//
//int main()
//{
//	//cout << A::_scount << endl;
//	//cout << sizeof(A) << endl; //1
//
//	cout << A::GetACount() << endl;     //0
//	A a1, a2;
//	cout << A::GetACount() << endl;		//2
//	A a3;
//	cout << A::GetACount() << endl;		//3
//
//	{	//局部域，出去则销毁
//		A a4;
//		cout << A::GetACount() << endl;	//4
//	}
//
//	cout << A::GetACount() << endl;		//3
//	cout << a3.GetACount() << endl;		//3
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//// 前置声明，都则A的友元函数声明编译器不认识B
//class B;
//
//class A
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b1 << endl;
//}
//
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class B;
//
//class A
//{
//	friend void Func1(const A& aa, const B& bb);
//
//private:
//	int a1 = 1;
//	int a2 = 2;
//};
//
//class B
//{
//	friend void Func1(const A& aa, const B& bb);
//
//private:
//	int b1 = 3;
//	int b2 = 4;
//};
//
//void Func1(const A& aa, const B& bb)
//{
//	cout << aa.a1 << bb.b1 << endl;
//}
//
//int main()
//{
//	A a;
//	B b;
//	Func1(a, b);
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//// 前置声明，都则A的友元函数声明编译器不认识B
//class B;
//
//class A
//{
//	// 友元声明
//	friend class B;
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//public:
//	void Print(const A& aa)
//	{
//		cout << aa._a1 << endl;
//		cout << _b1 << endl;
//	}
//
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//
//int main()
//{
//	A a;
//	B b;
//
//	b.Print(a);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	class B  //B默认是A的友元函数
//	{
//	public:
//		void Func(const A& aa)
//		{
//			cout << aa._a1 << "  " << aa._a2 << endl;
//			cout << _b1 << "  " << _b2 << endl;
//		}
//
//	private:
//		int _b1 = 3;
//		int _b2 = 4;
//	};
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//int main()
//{
//	A a;
//	A::B b;
//	b.Func(a);
//
//	return 0;
//}

#include<iostream>
using namespace std;

class A
{
public:
	A(int n)
		:a((int*)malloc(sizeof(int)* n))
		,size(0)
		,capacity(n)
	{
		if (a == nullptr)
		{
			perror("malloc fail");
			return;
		}
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int* a;
	int size;
	int capacity;
};

int main()
{
	// 有变量名(有名对象)
	A a(4);

	//无变量名(匿名对象)
	A(4);
	

	return 0;
}