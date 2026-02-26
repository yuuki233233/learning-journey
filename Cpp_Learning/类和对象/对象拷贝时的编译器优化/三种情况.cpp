#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	A(int a = 0)
		:_a1(a)
	{
		cout << "A(int a = 0)" << endl;
	}

	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;

		if (this != &aa)
		{
			_a1 = aa._a1;
		}

		return *this;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a1 = 1;
};

//没有传值返回
//(A aa)没有&(引用)，走拷贝构造
void func1(A aa)
{
}

int main()
{
	//构造+拷贝构造
	A aa1;
	func1(aa1);

	//隐式类型，连续构造+拷贝构造 -> 直接构造
	func1(1);

	//一个表达式(匿名函数)中，连续构造+拷贝构造 -> 一个构造
	func1(A(2));
	return 0;
}

//传返回值
A func2()
{
	A aa;
	return aa;
}


int main()
{
	//拷贝构造+构造 -> 直接构造
	A aa1 = 1;

	//构造+拷贝构造
	func1(aa1);

	//aa2为引用 + 构造
	const A& aa2 = 1;


	//隐式类型，连续构造+拷贝构造 -> 直接构造
	func1(1);

	//一个表达式(匿名函数)中，连续构造+拷贝构造 -> 一个构造
	func1(A(2));

	//不优化的情况下传值返回，编译器会生成一个拷贝返回对象的临时对象作为函数调用表达式的返回值
	//优化的情况下，将构造的局部对象和拷贝构造的临时对象优化为直接构造
	func2();

	//vs2019：返回一个表达式中，连续拷贝构造+拷贝构造 -> 一个拷贝构造
	//vs2022：优化的情况下，进行跨行合并优化，将构造的局部对象aa和拷贝的临时对象和接收返回值对象aa2优化为一个直接构造
	A aa3 = func2();

	//vs2019：返回一个表达式中，开始构造，中间拷贝构造+赋值重载
	//vs2022：跨行合并优化，将构造的局部对象aa和拷贝临时对象合并为一个直接构造
	aa1 = func2();

	return 0;
}