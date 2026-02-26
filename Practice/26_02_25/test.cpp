#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//struct Goods
//{
//	string _name; // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
//	// ...
//
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{
//	}
//};
//
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "⾹蕉", 3, 4 }, { "橙⼦", 2.2, 3
//	}, { "菠萝", 1.5, 4 } };
//
//	// 类似这样的场景，我们实现仿函数对象或者函数指针⽀持商品中
//	// 不同项的⽐较，相对还是⽐较⿇烦的，那么这⾥lambda就很好⽤了
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price;
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price;
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate;
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate > g2._evaluate;
//		});
//
//	return 0;
//}

#include<functional>

//// 两个int类型参数
//int f(int x, int y)
//{
//	return x + y;
//}
//
//struct Function
//{
//	int operator()(int x, int y)
//	{
//		return x + y;
//	}
//};
//
//int main()
//{
//	// 语法: function<return type (Parameter, Parameter...)> Object = 
//	// 语法条件: 需保持参数与个数相同
//	function<int(int, int)> f1 = f;
//	function<int(int, int)> f2 = Function();
//	function<int(int, int)> f3 = [](int a, int b) { return a + b; };
//
//	cout << f1(1, 2) << endl;  // 3
//	cout << f2(1, 2) << endl;  // 3
//	cout << f3(1, 2) << endl;  // 3
//
//	return 0;
//}

// 逆波兰表达式 C++98 与 C++11 的写法
//#include<stack>
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		for (auto& str : tokens) {
//			if (str == "+" || str == "-" || str == "*" || str == "/") {
//				int right = st.top();
//				st.pop();
//
//				int left = st.top();
//				st.pop();
//
//				switch (str[0])
//				{
//				case '+':
//					st.push(left + right);
//					break;
//				case '-':
//					st.push(left - right);
//					break;
//				case '*':
//					st.push(left * right);
//					break;
//				case '/':
//					st.push(left / right);
//					break;
//				}
//			}
//			else
//			{
//				st.push(stoi(str));
//			}
//		}
//
//		return st.top();
//	}
//};
//
//#include<map>
//// 使用map映射string和function的方式
//// 这种方式的最大优势之一是方便扩展
//class Solution {
//public:
//	int evalRPN(vector<string>& token) {
//		stack<int> st;
//		// function作为map的映射可调用对象的类型
//		map<string, function<int(int, int)>> opFuncMap = {
//			{"+", [](int x, int y) { return x + y; }},
//			{"-", [](int x, int y) { return x - y; }},
//			{"*", [](int x, int y) { return x * y; }},
//			{"/", [](int x, int y) { return x / y; }},
//		}; // 多参数的隐式类型转换
//
//		for (auto& str : token)
//		{
//			if (opFuncMap.count(str)) // 如果是操作符，调用对应的lambda
//			{
//				int right = st.top();
//				st.pop();
//				int left = st.top();
//				st.pop();
//
//				int ret = opFuncMap[str](left, right);
//				st.push(ret);
//			}
//			else
//			{
//				st.push(stoi(str));
//			}
//		}
//
//		return st.top();
//	}
//};


int f(int a, int b)
{
	return a + b;
}

struct Functor
{
public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};

class Plus
{
public:
	Plus(int n = 10)
		:_n(n)
	{
	}

	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return (a + b) * _n;
	}
private:
	int _n;
};

int main()
{
	// 包装静态成员函数需指定类域（静态成员可不加&）
	function<int(int, int)> f1 = &Plus::plusi;
	cout << f1(1, 1) << endl;

	/* 方法一 */
	// 包装成员成员函数需指定类域并在前面加上&才能获得地址
	// 而且普通成员函数还有一个隐含的this指针参数，所以绑定是传对象或对象的指针即可
	function<double(Plus*, double, double)> f2 = &Plus::plusd;
	Plus pd;
	cout << f2(&pd, 1.1, 1.1) << endl;

	/* 方法二：直接用对象 */
	// 为什么下面的Plus不需要*也可以调用
	// 如果是成员函数，编译器就用 .* 进行强制调用
	// .* 调用就要显示传递 Plus 对象地址，如果是指针直接存对象，如果是对象编译器会自己取地址
	function<double(Plus, double, double)> f3 = &Plus::plusd;
	cout << f3(pd, 1.1, 1.1) << endl;

	/* 方法三：对象用右值引用&&，可以用匿名对象 */
	function<double(Plus&&, double, double)> f4 = &Plus::plusd;
	cout << f4(move(pd), 1.1, 1.1) << endl;
	cout << f4(Plus(), 1.1, 1.1) << endl;

	return 0;
}