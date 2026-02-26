#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

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

	~Stack()
	{
		free(_a);
		_a == nullptr;
		_capacity = _top = 0;
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
	//编译器默认生成MyQueue的析构函数调用了Stack的析构，释放的Stack内部的资源
private:

	//自定义类型，会调用自己的析构函数
	Stack pushst;
	Stack popst;
};

int main()
{
	MyQueue mq;

	return 0;
}