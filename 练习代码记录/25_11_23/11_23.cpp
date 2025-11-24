//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;

//int main()
//{
//	int a = 10;
//
//	//编译报错：“ra”必须初始化引用
//	//int& b;
//
//	//正确引用
//	int& b = a;
//
//	int c = 20;
//	//这里并非让b引用c，因为C++引用不能改变指向
//	//这里是一个赋值
//	b = c;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//typedef struct SeqList
//{
//	int a[10];
//	int size;
//}STL;
//
////一些主要用C代码实现版本数据结构教材中，使用C++引用替代指针传参，目的是简化程序，避开复杂的指针
//void SeqPushBack(SLT& sl, int x)
//{
//}
//
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTNode, * PNode;
//
////指针变量也可以取别名，这里LTNode*&phead就是给指针变量取别名
////这样就不需要用二级指针了，相对而言简化了程序
////void ListPushBack(LTNode**phead,int x)
////void ListPushBack(LTNode*&phead,int x)
//void ListPushBack(PNode& phead, int x)
//{
//	PNode newnode = (PNode)malloc(sizeof(LTNode));
//	newnode->val = x;
//	newnode->next = NULL;
//	if (phead == NULL)
//	{
//		phead = newnode;
//	}
//	else
//	{
//		//...
//	}
//}
//
//int main()
//{
//	PNode plist = NULL;
//	ListPushBack(plist, 1);
//
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	// 编译报错：error C2440: “初始化”: 无法从“const int”转换为“int &”
//	// 这里的引用是对a访问权限的放大
//	//int& ra = a;
//
//	//正确写法
//	const int& ra = a;
//
//	//编译器报错：不能给常量赋值
//	//ra++;
//
//	//这里的引用时对b访问权限的缩小
//	int b = 20;
//	const int& rb = b;
//
//	//编译报错：不能给常量赋值
//	//rb++;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	const int& ra = 30;
//
//	//编译报错：无法从int转换为int&
//	//int& rb = a * 3;
//	const int& rb = a * 3;//因为a*3要创建临时对象
//
//	double d = 12.34;
//	//编译报错：无法从int转换为int&
//	//int& rd = d;
//	const int& rd = d;//因为类型的转变，需要创建临时变量
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//
//	return ret;
//}
//
//int main()
//{
//	//可以通过汇编观察程序是否展开
//	//有call Add语句就是没有展开
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#define ADD(a, b) ((a) + (b))
////不能在末尾加分号，加分号在C++中导致错误
////外面要加括号，可能会因为运算符优先级问题，导致数据错误
////里面要加括号，在比较运算符时，会导致问题
//
//int main()
//{
//	int ret = ADD(1, 2);
//
//	cout << ADD(1, 2) << endl;     //3
//
//	cout << ADD(1, 2) * 5 << endl; //如果不在外层加括号则是11
//
//	int x = 1, y = 2;
//	ADD(x & y, x | y); // -> (x&y + x|y);
//					   //+的优先级大于&和|
//
//	return 0;
//}

///*test.h*/
//inline void Func(int x);
//
///*test.cpp*/
//#include"test.h";
//void Func(int x)
//{
//	cout << x << endl;
//}
//
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	//链接错误：无法解析的外部符号
//	Func(1);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//
//int main()
//{
//	f(0);//f(int x)
//
//	//本想通过f(NULL)调用指针版本的f(int*)函数，但是由于NULL被定义成0，
//	f(NULL);//f(int x)
//
//	f((int*)NULL);//f(int* ptr)
//
//	//error:2个重载中没有一个可以转换所有参数类型
//	//f((void*)NULL);
//
//	f(nullptr); //f(int* ptr)
//	return 0;
//}

#include<iostream>
using namespace std;

class Stack
{
	void Push(int x)
	{ }
	void Pop()
	{ }
	int Top()
	{ }

	int* a;
	int top;
	int capacity;
};