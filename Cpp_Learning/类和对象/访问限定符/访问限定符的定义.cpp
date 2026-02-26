#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class Stack
//{
//	//默认私有
//	void Push(int x)
//	{
//	}
//	void Pop()
//	{
//	}
//	int Top()
//	{
//	}
//
//	int* a;
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	Stack st;
//	//因为是私有，无法访问
//	st.Push();
//	return 0;
//}

//class Stack
//{
//	//公有（可以访问）
//public:
//	void Push(int x)
//	{
//	}
//	void Pop()
//	{
//	}
//	int Top()
//	{
//	}
//
//	//私有（不能访问）
//private:
//	int* a;
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	//因为是公有，可以访问
//	Stack st;
//	st.Push(4);
//
//	return 0;
//}

class Stack
{
	//尽管下面是公有的，上面也默认私有
	void Destory();

	//公有（可以访问）
public:
	void Push(int x)
	{
	}
	void Pop()
	{
	}
	int Top()
	{
	}

	//私有（不能访问）
private:
	int* a;
	int top;
	int capacity;
};