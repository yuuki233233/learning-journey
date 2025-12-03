#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
typedef int STDataType;
class Stack
{
public:
	//默认构造函数，若改成int n则不是默认构造函数
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