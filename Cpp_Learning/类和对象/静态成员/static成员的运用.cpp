#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		_scount++;
	}

	A(const A& a)
	{
		_scount++;
	}

	~A()
	{
		_scount--;
	}

	static int GetACount()
	{
		return _scount;
	}

	static int M()
	{
		//静态成员函数不能访问非静态
		//_a;
	}

	void Print()
	{
		//非静态成员函数可以访问静态
		cout << A::GetACount() << endl;
		cout << _scount << endl;
	}

private:
	static int _scount;
	int _a;
};

//类外初始化
int A::_scount = 0;

int main()
{
	//cout << A::_scount << endl;
	//cout << sizeof(A) << endl; //1

	cout << A::GetACount() << endl;     //0
	A a1, a2;
	cout << A::GetACount() << endl;		//2
	A a3;
	cout << A::GetACount() << endl;		//3

	{	//局部域，出去则销毁
		A a4;
		cout << A::GetACount() << endl;	//4
	}

	cout << A::GetACount() << endl;		//3
	cout << a3.GetACount() << endl;		//3

	return 0;
}