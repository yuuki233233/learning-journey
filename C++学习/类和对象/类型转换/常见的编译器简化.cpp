#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class A
{
public:
	// 构造函数explicit就不再⽀持隐式类型转换
	// explicit A(int a1)
	A(int a1 = 1)
	{
		_a1 = a1;
	}

	void Print()
	{
		cout << _a1 << " " << _a2 << endl;
	}

	//explicit A(int a1, int a2)
	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{
	}

private:
	int _a1 = 1;
	int _a2 = 2;
};

class Stack
{
public:
	//原本A a3 = 3, Push(a3)
	//简化成Push(3)
	void Push(const A& aa)
	{
		//...
	}

private:
	A* _arr[10];
	int _top;
};

int main()
{
	A aa1(1);
	aa1.Print();

	// 2构造⼀个A的临时对象，再⽤这个临时对象拷贝构造aa2
	// 编译器遇到连续构造+拷贝构造->优化为直接构造
	A aa2 = 2;
	aa2.Print();

	A& rra1 = aa2;
	const A& raa2 = 2;//类型转换(具有常性)

	int i = 1;
	double d = i;
	const double& rd = i;

	Stack st;

	//效果一样
	//------------------
	A aa3(3);
	st.Push(aa3);
	//------------------
	st.Push(3);
	//------------------


	//多参数
	A aa5 = { 1,1 };
	st.Push(aa5);
	st.Push({ 3, 3 });

	const A& aa6 = { 2,2 };

	return 0;
}