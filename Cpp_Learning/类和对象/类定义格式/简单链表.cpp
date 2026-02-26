#include<iostream>
using namespace std;

//C++升级struct升级成了类
//1、类里面可以定义函数
//2、struct名称就可以代表类型

//C++兼容C中struct的用法
typedef struct ListNodeC
{
	struct ListNOdeC* next;
	int val;
}LTNode;

//C++中不再需要typedef，ListNodeCPP就可以代表类型
struct ListNodeCPP
{
	//C++中，struct可以定义函数
	void Init(int x)
	{
		next = nullptr;
		val = x;
	}

	//不需要用struct ListNodeCPP
	ListNodeCPP* next;
	int val;
};

int main()
{
	return 0;
}