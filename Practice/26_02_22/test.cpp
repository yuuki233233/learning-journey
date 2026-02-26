#define _CRT_SECURE_NO_WARNINGS
#include"String.h"
#include"List.h"

class Solution {
public:
	// 传值返回需要拷贝
	yuuki::string addStrings(yuuki::string num1, yuuki::string num2) {
		yuuki::string str;
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		// 进位
		int next = 0;
		while (end1 >= 0 || end2 >= 0)
		{
			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
			int ret = val1 + val2 + next;
			next = ret / 10;
			ret = ret % 10;
			str += ('0' + ret);
		}
		if (next == 1)
			str += '1';
		reverse(str.begin(), str.end());
		//cout << &str << endl;

		return str;
	}
};

//template<class T>
//void f1(T& x)
//{
//	cout << "f1(T& x)" << endl;
//}
//
//template<class T>
//void f2(T&& x)
//{
//	cout << "f2(T&& x)" << endl;
//}
//
//int main()
//{
//	typedef int& lref;
//	typedef int&& rref;
//	int n = 0;
//
//	lref& r1 = n; // r1 的类型是 int&
//	lref&& r2 = n; // r2 的类型是 int&
//	rref& r3 = n; // r3 的类型是 int&
//	rref&& r4 = 1; // r4 的类型是 int&&
//
//	// 没有折叠->实例化为void f1(int& x)
//	f1<int>(n);
//	//f1<int>(0); // 报错
//
//	// 折叠->实例化为void f1(int& x)
//	f1<int&>(n);
//	//f1<int&>(0); // 报错
//
//	// 折叠->实例化为void f1(int& x)
//	f1<int&&>(n);
//	//f1<int&&>(0); // 报错
//
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&>(n);
//	f1<const int&>(0);
//
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&&>(n);
//	f1<const int&&>(0);
//
//	// 没有折叠->实例化为void f2(int&& x)
//	//f2<int>(n); // 报错
//	f2<int>(0);
//
//	// 折叠->实例化为void f2(int& x)
//	f2<int&>(n);
//	//f2<int&>(0); // 报错
//
//	// 折叠->实例化为void f2(int&& x)
//	//f2<int&&>(n); // 报错
//	f2<int&&>(0);
//	return 0;
//}

//// 万能引用
//template<class T>
//void Function(T&& t)
//{
//	int a = 0;
//	T x = a;
//	// x++;
//
//	cout << &a << endl;
//	cout << &x << endl << endl;
//}
//
//int main()
//{
//	Function(10); // 右值
//
//	int a;
//	Function(a); // 左值
//
//	Function(std::move(a)); // 右值
//
//	const int b = 8;
//	Function(b); // const 左值, 不能x++
//
//	Function(std::move(b)); // const 右值, 不能x++
//
//	return 0;
//}

//// 完美转发
//void Fun(int& x) { cout << "左值引⽤" << endl; }
//void Fun(const int& x) { cout << "const 左值引⽤" << endl; }
//void Fun(int&& x) { cout << "右值引⽤" << endl; }
//void Fun(const int&& x) { cout << "const 右值引⽤" << endl; }
//template<class T>
//void Function(T&& t)
//{
//	//Fun(t);
//	Fun(forward<T>(t));
//}
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(10); // 右值
//
//	int a;
//	// a是左值，推导出T为int&，引⽤折叠，模板实例化为void Function(int& t)
//	Function(a); // 左值
//
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(std::move(a)); // 右值
//
//	const int b = 8;
//	// a是左值，推导出T为const int&，引⽤折叠，模板实例化为void Function(const int&t)
//	Function(b); // const 左值
//
//	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&t)
//	Function(std::move(b)); // const 右值
//
//	return 0;
//}


//// 可变参数模板
//// 
//// 0-N个参数
//template <class ...Args>
//void Print(Args&&... args)
//{
//	/* sizeof...计算参数包中有多少个参数 */
//	cout << sizeof...(args) << endl;
//}
//
//int main()
//{
//	double x = 2.2;
//	Print(); // 包⾥有0个参数
//	Print(1); // 包⾥有1个参数
//	Print(1, string("xxxxx")); // 包⾥有2个参数
//	Print(1.1, string("xxxxx"), x); // 包⾥有3个参数
//	return 0;
//}
//
////原理1：编译本质这里会结合引用折叠规则实例化出一下四个函数
//void Print();
//void Print(int&& arg1);
//void Print(int&& arg1, string&& arg2);
//void Print(double&& arg1, string&& arg2, double& arg3);
//
////原理2：更本质去看没有可变参数模板，我们实现出这样的多个函数模板才能支持
////		这里的功能，有了可变参数模板，我们写的更少，其他的让编译器自己实现
////		她是类型泛化基础上叠加数量变化，让我们泛型编程更加灵活
//void Print();
//
//template <class T1>
//void Print(T1&& arg1);
//
//template <class T1, class T2>
//void Print(T1&& arg1, T2&& arg2);
//
//template <class T1, class T2, class T3>
//void Print(T1&& arg1, T2&& arg2, T3&& arg3);
// //...


// 包扩展（解析出参数包的内容）
 
// 递归解析
//template<class ...Args>
//void ShowList()
//{
//	// 编译器递归终止条件，参数包是0个是，直接匹配这个函数
//	cout << endl;
//}
//
//template<class T, class ...Args>
//void ShowList(T&& x, Args&&... args)
//{
//	cout << x << " ";
//	// args是N个参数包
//	// 调用ShowList，参数包的第一个传给x，剩下N-1传给第二个参数包
//	ShowList(args...);
//}
//
//template<class ...Args>
//void Print(Args&&... args)
//{
//	/*
//	* 1. 如果是0个参数的参数包，直接调用 void ShowList()
//	*
//	* 2. 如果是多个参数的参数包，直接调用 void ShowList(T x, Args&&... args)
//	* 一个参数的参数包推给x，剩下参数包推给ShowList(args...)，递归调用自己
//	*/
//	ShowList(args...);
//}
//
//
//// 不用递归解析参数，一个一个参数解析
////template<class T>
////const T& GetArg(const T& x)
////{
////	cout << x << " ";
////	return x;
////}
//
///*可以写成以下这种形式，与上述一样*/
//template<class T>
//int GetArg(const T& x)
//{
//	cout << x << " ";
//	return 0;
//}
//
//// 利用 Arguments 调用多个参数的GetArg(args)...
//template<class ...Args>
//void Arguments(Args... args)
//{ }
//
//template<class ...Args>
//void Print(Args&&... args)
//{
//	// 在 Arguments() 中，有1个参数，解析1个参数，有2个解析2个
//	Arguments(GetArg(args)...);
//}
///* 编译器实例化为下面代码 */
////void Print(Args&&... args)
////{
////	Arguments(GetArg(x), GetArg(y), GetArg(z));
////}
//
//int main()
//{
//	double x = 2.2;
//	Print(); // 包⾥有0个参数
//	Print(1); // 包⾥有1个参数
//	Print(1, string("xxxxx")); // 包⾥有2个参数
//	Print(1.1, string("xxxxx"), x); // 包⾥有3个参数
//	return 0;
//}

// push_back & emplace_back
//
#include<list>
int main()
{
	list<yuuki::string> li;

	                                            /*单参数*/
	yuuki::string s1("11111111111111");
	yuuki::string s2("11111111111111");

	/* 传左值，跟 push_back 一样，走拷贝构造 */
	li.push_back(s1);
	cout << "***************************************" << endl;

	li.emplace_back(s1);
	cout << "***************************************" << endl;

	/* 传右值，跟push_back 一样，走移动构造 */
	li.push_back(move(s1));
	cout << "***************************************" << endl;

	li.emplace_back(move(s2));
	cout << "***************************************" << endl;

	/* 直接传参数，push_back 隐式类型转换，走构造 + 移动构造*/
	li.push_back("11111111111111111");
	cout << "***************************************" << endl;
	/*
	* emplace_back 走构造
	* 因为直接推出来 const char*，就可以直直接把参数往下传，再走完美转发
	*/
	li.emplace_back("11111111111111111");
	cout << "***************************************" << endl << endl;

	/*
	* 总结 emplace：
	* 深拷贝：emplace 系类少了个移动构造，会快一些
	* 浅拷贝：emplace 系列没有移动构造，再快一些
	*/

	                                             /*多参数*/
	list<pair<yuuki::string, int>> li2;
	/*
	* 跟push_back一样
	* 构造pair + 拷贝/移动构造pair到list的节点中data上
	*/
	pair<yuuki::string, int> kv("苹果", 1);
	li2.push_back(kv);
	cout << "***************************************" << endl;
	li2.emplace_back(kv);
	cout << "***************************************" << endl;

	//跟push_back一样
	li2.push_back(move(kv));
	cout << "***************************************" << endl;
	li2.emplace_back(move(kv));
	cout << "***************************************" << endl;

	/* 不同的效果 */
	// push_back 只有 pair 一个参数，( "梨子", 2 )有两个参数，所以得走隐式类型转换
	// 反而 emplace_back 不支持隐式类型转化
	li2.push_back({ "梨子", 2 });
	cout << "***************************************" << endl;

	// 相当于一直往下传参数包，直到遇到 _data，构造成 pair 类型
	li2.emplace_back("梨子", 2);
	cout << "***************************************" << endl;

	/*
	* 总结 emplace系列兼容 push系列和 insert的功能
	* 部分场景下 emplace可以直接构造，push和 insert是 构造 + 移动构造 或 构造 + 拷贝构造
	* 所以 emplace综合而言更好用更强大，推荐用 emplace代替 push和 insert
	*/

	return 0;
}