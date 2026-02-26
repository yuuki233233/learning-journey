//#define _CRT_SECURE_NO_WARNINGS

//class A
//{
//public:
//	A(int a = 1)
//		:_a(a)
//	{
//		cout << "A(int)" << endl;
//	}
//
//	A(const A& a)
//	{
//		cout << "A(const A& (int))" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void Print()
//	{
//		cout << "_a = " << _a << endl;
//	}
//
//private:
//	int _a;
//};
//
//A Func()
//{
//	A aa;
//
//	return aa;
//}
//
//int main()
//{
//	A a;
//	A aa = Func();
//
//	return 0;
//}

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
//	{}
//
//	//Date const this;
//	Date* operator&()
//	{
//		//可以是自己定义的值，但是要修改成定义类型
//
//		return this;
//		//return nullptr;
//		//return (Date*)2256FF00X30
//	}
//
//	//const Date const this;
//	const Date* operator&() const
//	{
//		//可以是自己定义的值，但是要修改成定义类型
//
//		return this;
//		//return nullptr;
//		//return (Date*)2256FF00X46   
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//
//	return 0;
//}


//内置类型
//----------------------------------------------------------------------------
//int main()
//{
//	//申请内存
//	int* p1 = new int;
//	int* p2 = new int[10];
//
//	//销毁
//	delete p1;
//	delete[] p2;
//
//	//申请对象+初始化
//	int* p3 = new int(0);
//	int* p4 = new int[10] {0};//全部初始化为0
//	int* p5 = new int[10] {1, 2, 3, 4, 5};//初始化一部分，剩下的为0
//	delete p3;
//	delete[] p4;
//	delete[] p5;
//	return 0;
//}
//----------------------------------------------------------------------------



//类类型
//----------------------------------------------------------------------------
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a1, int a2 = 0)
//		:_a1(a1)
//		,_a2(a2)
//	{
//		cout << "A(int a1 = 0, int a2 = 0)" << endl;
//	}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	A& operator=(const A& aa)
//	{
//		_a1 += 100;
//
//		return *this;
//	}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//int main()
//{
//	A* p1 = new A(1); //必须默认构造
//	A* p2 = new A(2, 2);
//	//A* p3 = new A[3]; //默认默认构造则报错
//
//
//	//第一种写法
//	A aa1(1, 1);
//	A aa2(2, 2);
//	A aa3(3, 3);
//	A* p3 = new A[3]{ aa1, aa2, aa3 };//拷贝构造
//
//	//第二种写法:匿名构造
//	//编译器直接优化成直接构造
//	A* p4 = new A[3]{ A(1, 1), A(2, 2), A(3, 3) };
//
//	//第三种写法：隐式类型转换
//	//编译器直接优化成直接构造
//	A* p5 = new A[3]{ {1,1},{2,2},{3,3} };
//
//	return 0;
//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//struct ListNode
//{
//	int val;
//	ListNode* next;
//
//	ListNode(int x)
//		:val(x)
//		,next(nullptr)
//	{ }
//};
//
//int main()
//{
//	//与C语言的区别是：自动调用构造函数和析构函数
//	A* p1 = new A;
//	A* p2 = new A(1);
//
//	delete p1;
//	delete p2;
//
//	//用new申请类类型和自定义类型的空间：自动初始化与析构
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(1);
//	ListNode* n3 = new ListNode(1);
//	ListNode* n4 = new ListNode(1);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//
//	return 0;
//}
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//void func()
//{
//	int n = 1;
//	while (1)
//	{
//		void* p1 = new char[1024 * 1024];
//		cout << p1 << "->" << n << endl;
//		++n;
//	}
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}
//----------------------------------------------------------------------------

#include<iostream>
using namespace std;

class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a1 = 1;
	int _a2 = 2;
};

class B
{
private:
	int _b1 = 1;
	int _b2 = 2;
};


int main()
{
	//内置类型
	// 
	// 
	//不会报错(内核是)：
	//new operator[]最终调用malloc
	//delete operator[]最终调用free
	int* p1 = new int[10];  // -> malloc
	delete p1;				// -> free
	free(p1);
 


	//自定义类型
	// 
	// 
	//因为B* p1没有调用析构函数，析构被编译器优化掉
	//因为没有析构，前面没有开4个字节，一共80个字节且释放地方相同，所以可以正常释放
	B* p1 = new B[10];
	delete p1;

	//这里由于调用了析构函数，在创建的80字节内存前加了4字节，一共有84字节
	//这里只用delete却没有用delete[]，会让p2指向第80字节，释放空间时因为释放位置不对而崩溃
	A* p2 = new A[10];
	delete p2;
}