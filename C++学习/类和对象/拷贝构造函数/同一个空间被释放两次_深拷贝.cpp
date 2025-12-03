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
			perror("malloc申请空间失败");
			return;
		}
		_capacity = n;
		_top = 0;
	}

	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
				sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			_a = tmp;
			_capacity = newcapacity;
		}
		_a[_top++] = x;

	}

	//-----------------------------------------------
	~Stack()
	{
		cout << "~Stack()" << endl;
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
	//-----------------------------------------------
private:
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};

int main()
{
	Stack st1;
	st1.Push(1);
	st1.Push(2);

	//-----------------------------------------------
	// Stack不显示实现拷贝构造，用自动生成的拷贝构造完成浅拷贝
	// 会导致st1和st2里面的_a指针指向同一块资源，析构时会析构两次，程序崩溃
	Stack st2(st1);
	//-----------------------------------------------

	return 0;
}