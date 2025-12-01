#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>

using namespace std;

class Stack
{
	//公有
public:
	//成员函数
	void Init(int n = 4)
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

	void Push(int x)
	{
		if (capacity == top)
		{
			int newcapacity = capacity == 0 ? 4 : sizeof(int) * 2;
			int* tmp = (int*)realloc(array, sizeof(int) * newcapacity);
			if (tmp == nullptr)
			{
				perror("realloc fail");
				return;
			}
			array = tmp;
			capacity = newcapacity;
		}
		array[top++] = x;
	}

	int Top()
	{
		assert(top > 0);
		return array[top - 1];
	}

	void Destory()
	{
		free(array);
		array = nullptr;
		top = capacity = 0;
	}

	//私有
private:
	//成员变量
	int* array;
	size_t capacity;
	size_t top;
};//分号不能省略

int main()
{
	Stack st;
	st.Init();//缺省参数
	st.Push(1);
	st.Push(2);

	cout << st.Top() << endl;

	st.Destory();

	return 0;
}