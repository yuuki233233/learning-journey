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

#include<iostream>
using namespace std;

int main()
{


	return 0;
}