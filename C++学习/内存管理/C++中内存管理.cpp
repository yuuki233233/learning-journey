#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//内置类型
void test01()
{
    // 基本用法
    int* p1 = new int;         // 分配单个int空间
    int* p2 = new int[10];     // 分配10个int的数组

    // 初始化
    int* p3 = new int(0);      // 分配并初始化为0
    int* p4 = new int[10] {0};  // 数组初始化，剩余元素为0
    int* p5 = new int[10] {1, 2, 3, 4, 5}; // 部分初始化

    // 释放空间
    delete p1;
    delete[] p2;
    delete p3;
    delete[] p4;
    delete[] p5;
}

//类类型
class A
{
public:
	A(int a1, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{
		cout << "A(int a1 = 0, int a2 = 0)" << endl;
	}

	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		_a1 += 100;

		return *this;
	}

private:
	int _a1 = 1;
	int _a2 = 2;
};

int main()
{
	A* p1 = new A(1); //必须默认构造
	A* p2 = new A(2, 2);
	//A* p3 = new A[3]; //默认默认构造则报错


	//第一种写法
	A aa1(1, 1);
	A aa2(2, 2);
	A aa3(3, 3);
	A* p3 = new A[3]{ aa1, aa2, aa3 };//拷贝构造

	//第二种写法:匿名构造
	//编译器直接优化成直接构造
	A* p4 = new A[3]{ A(1, 1), A(2, 2), A(3, 3) };

	//第三种写法：隐式类型转换
	//编译器直接优化成直接构造
	A* p5 = new A[3]{ {1,1},{2,2},{3,3} };

	return 0;
}