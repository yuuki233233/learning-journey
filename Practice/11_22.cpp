//C++兼容C
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int main()
//{
//	printf("hello world\n");
//
//	return 0;
//}

//C语言命名冲突
//#include<stdio.h>
//#include<stdlib.h>
//int rand = 9;
//
//int main()
//{
//	printf("%d", rand);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
////域
//namespace yuuki
//{
//	// 命名空间中可以定义变量/函数/类型
//	int rand = 10;	//常量
//
//	//函数
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	//结构体
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//
//}//注意：没有分号
//
//int main()
//{
//	// 这里默认是访问的是全局的rand函数指针
//	printf("rand = %p\n", rand);
//	// 这里指定bit命名空间中的rand
//	printf("yuuki::rand = %d\n", yuuki::rand);
//
//	printf("yuuki::Add = %p\n", yuuki::Add);
//	printf("yuuki::Add(1, 2) = %d\n", yuuki::Add(1, 2));
//
//	struct yuuki::Node node;
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
////域
//namespace yuuki
//{
//	int rand = 10;
//}
//
//int a = 0;
//
//int main()
//{
//	int a = 1;
//	cout << "a = " << a << endl; //1
//
//	// ::域作用限定符
//	cout << "::a = " << ::a << endl; //0
//	cout << "yuuki::rand = " << yuuki::rand << endl; //10
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//
//namespace yuuki
//{
//	namespace A
//	{
//		int rand = 10;
//		int Add(int x, int y)
//		{
//			return x + y;
//		}
//	}
//
//	namespace B
//	{
//		int rand = 20;
//		int Sub(int x, int y)
//		{
//			return x - y;
//		}
//	}
//}
//
//int main()
//{
//	printf("yuuki->A->rand = %d\n", yuuki::A::rand);
//	printf("yuuki->B->rand = %d\n", yuuki::B::rand);
//
//	printf("yuuki->A->Add = %d\n", yuuki::A::Add(1, 1));
//	printf("yuuki->B->Sub = %d\n", yuuki::B::Sub(1, 1));
//
//	return 0;
//}

//#include<stdio.h>
//namespace yuuki
//{
//	int a = 0;
//	int b = 1;
//}
//int main()
//{
//	// 编译报错：error C2065: “a”: 未声明的标识符
//	printf("%d\n", a);
//	return 0;
//}

//// 指定命名空间访问
//#include<stdio.h>
//namespace N
//{
//	int a = 10;
//	int b = 20;
//}
////int main()
////{
////	printf("%d\n", N::a);
////	return 0;
////}
//
//// using将命名空间中某个成员展开
//using N::b;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}

//// 展开命名空间中全部成员
//using namespce N;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 0;
//	double b = 0.1;
//	char c = 'x';
//
//	cout << a << " " << b << " " << c << endl;
//	std::cout << a << " " << b << " " << c << std::endl;
//
//	// 可以⾃动识别变量的类型
//	cin >> a >> b >> c;
//	cout << a << " " << b << " " << c << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	// 在io需求⽐较⾼的地⽅，如部分⼤量输⼊的竞赛题中，加上以下3⾏代码
//	// 可以提⾼C++IO效率
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	return 0;
//}

//#include<iostream>
//#include<assert.h>
//using namespace std;
//
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func();
//	Func(10);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//// 全缺省
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//// 半缺省
//void Func2(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//
//	Func2(100);
//	Func2(100, 200);
//	Func2(100, 200, 300);
//
//	return 0;
//}

//// Stack.h
//#include<iostream>
//#include<assert.h>
//using namespace std;
//
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void STInit(ST* pS, int n = 4);
//
//// Stack.cpp
//#include"Stack.h"
////缺省参数不能声明和定义同时给
//void STInit(ST* pS，int n)
//{
//	assert(ps && n > 0);
//
//	ps->a = (STDataType*)malloc(n * sizeof(STDataType));
//	ps->top = 0;
//	ps->capacity = n;
//}
//
////test.cpp
//#include"Stack.h"
//int main()
//{
//	ST s1;
//	STInit(&s1);
//	//确定知道要插入1000个数据，初始化时一把开好，避免扩容
//	ST s2;
//	STInit(&s2, 1000);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//int main()
//{
//	cout << Add(1, 2) << endl;      //3
//	cout << Add(1.1, 2.2) << endl;  //3.3
//}

//#include<iostream>
//using namespace std;
//
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//int main()
//{
//	f();   //f()
//	f(1);  //f(int a)
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void f(int a, char b)
//{
//	cout << "f(int a, char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//
//int main()
//{
//	f(1, 'a'); //f(int a, char b)
//	f('a', 1); //f(char b, int a)
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//// 下⾯两个函数构成重载
//void Func()
//{
//	cout << "Func()" << endl;
//}
//
////缺省参数 + 函数重载
//void Func(int a = 10)
//{
//	cout << "Func(int a = 10)" << endl;
//}
//
//int main()
//{
//	// f()但是调用时，会报错，存在歧义，编译器不知道调用谁
//	Func();
//
//	//调用Func(int a = 10)
//	Func(1);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = 0;
//
//	// 引用：b和c是a的别名
//	int& b = a;
//	int& c = a;
//
//	// 也可以给别名b取别名，d相当于还是a的别名
//	int& d = b;
//
//	cout << "a = " << a << " b = " << b << endl;
//	cout << "c = " << c << " d = " << d << endl;
//
//	d++;
//
//	cout << "&a = " << &a << endl;
//	cout << "&b = " << &b << endl;
//	cout << "&c = " << &c << endl;
//	cout << "&d = " << &d << endl;
//
//	cout << "a = " << a << " b = " << b << endl;
//	cout << "c = " << c << " d = " << d << endl;
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//void Swap(int& rx, int& ry)
//{
//	int tmp = rx;
//	rx = ry;
//	ry = tmp;
//}
//
//int main()
//{
//	int x = 3, y = 6;
//	cout << "x = " << x << endl;
//	cout << "y = " << y << endl;
//
//	Swap(x, y);
//	cout << "x = " << x << endl;
//	cout << "y = " << y << endl;
//	return 0;
//}

#include"Stack.h"
#include<iostream>
using namespace std;

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST& rs, int n = 4)
{
	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
	rs.top = 0;
	rs.capacity = n;
}

//栈顶
void STPush(ST& rs, STDataType x)
{
	if (rs.top == rs.capacity)
	{
		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		rs.a = tmp;
		rs.capacity = newcapacity;
	}
	rs.a[rs.top] = x;
	rs.top++;
}

//int STTop(ST& rs)
int& STTop(ST& rs)
{
	assert(rs.top > 0);
	return rs.a[rs.top];
}

int main()
{
	//调用全局的
	ST st1;
	STInit(st1);
	STPush(st1, 1);
	STPush(st1, 2);

	cout << STTop(st1) << endl;

	STTop(st1) += 10;
	cout << STTop(st1) << endl;

	return 0;
}