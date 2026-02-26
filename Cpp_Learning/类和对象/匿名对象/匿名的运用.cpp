#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	A(int n)
		:a((int*)malloc(sizeof(int)* n))
		, size(0)
		, capacity(n)
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