#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Stack
{
public:
	//成员函数
	void Init(int n = 4);

private:
	//成员变量
	int* array;
	size_t capacity;
	size_t top;
};

//声明和定义分离，需要指定类域
void Stack::Init(int n)
{
	array = (int*)malloc(sizeof(int) * n);
	if (nullptr == array)
	{
		perror("malloc fail");
		return;
	}

	capacity = n;
	top = 0;
}

int main()
{
	Stack st;
	st.Init();

	return 0;
}
