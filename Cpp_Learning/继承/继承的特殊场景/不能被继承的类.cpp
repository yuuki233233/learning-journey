#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 方法2：final修饰（推荐）
class Base final
{
public:
	void func() { cout << "Base::func()" << endl; }
};

// class Derive : public Base {}; // 报错！Base被final修饰，不能继承