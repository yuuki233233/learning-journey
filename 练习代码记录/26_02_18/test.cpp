#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<iostream>
using namespace std;

struct Point
{
	int _x;
	int _y;
};

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		cout << "直接构造" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{
		cout << "拷贝构造" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

// C++98 和 C++11 {} 的比较
void tset01()
{
	/*C++98*/

	int a1[] = { 1,2,3,4,5 };
	int a2[5] = { 0 };
	Point p = { 1,2 };

	/*C++11*/

	// 内置类型
	int x1 = { 1 };

	// 自定义类型
	// { 2026, 2, 18 } 构造了Date临时变量，然后拷贝构造d1
	// 编译器优化后合二为一，变成直接构造
	Date d1 = { 2026, 2, 18 };
	// 这里d2引用的是{ 2025, 2, 18 }构造的临时对象
	const Date& d2 = { 2026, 2, 18 };

	// 注意：C++98支持单参数时类型转换，也可以不用{}
	Date d3 = { 2026 }; // 存在缺省值
	Date d4 = 2026;

	// 可省略=
	Point p1{ 1,2 };
	int x2{ 2 };
	Date d5{ 2026,2,18 };
	const Date& d6{ 2026,2,18 };


	vector<Date> v;
	// 有名对象传参
	v.push_back(d1);
	// 匿名对象传参
	v.push_back(Date(2026, 2, 18));
	// {}传参
	v.push_back({ 2026, 2, 18 });

}

void test02()
{
	initializer_list<int> mylist{ 10, 20, 30 };
	cout << "sizeof:" << sizeof(mylist) << endl;

	// begin和end两指针跟i地址接近，说明数组在栈上
	int i = 0;
	cout << "&i:" << &i << endl;
	cout << "mylist.begin():" << mylist.begin() << endl;
	cout << "mylist.end():" << mylist.end() << endl;

	// {}列表有多种写法
	vector<int> v1({ 1,2,3,4,5 });  // 直接构造
	vector<int> v2 = { 1,2,3,4,5 }; // 构造临时对象+临时对象拷贝 = 优化为直接构造
	const vector<int>& v3 = { 1,2,3,4,5 };

	// {}的嵌套
	map<string, string>  dict = { {"sort", "排序"}, {"string", "字符串"} };

	// initializer_list版本的复制支持
	v1 = { 10, 20, 30, 40,50 };
}

void test03()
{
	// 左值：可以取地址
	int* p = new int(0);
	int b = 1;
	const int c = b;
	string s("11111111");
	s[0] = 'x';

	cout << &c << endl;
	cout << (void*)&s[0] << endl;

	// 右值不能取地址
	10;
	b + b;
	fmin(b, b);
	string("11111111");

	/*cout << &10 << endl;
	cout << &(b+b) << endl;
	cout << &(fmin(b, b)) << endl;
	cout << &string("11111111") << endl;*/
}

void test04()
{
	// 左值：可以取地址
	int b = 1;
	int* p = new int(0);
	const int c = b;
	string s("11111111");
	s[0] = 'x';
	double x = 1.1, y = 2.2;

	// 左值引用给左值取别名
	int& r1 = b;
	int*& r2 = p;
	const int& r3 = c;
	string& r4 = s;
	char& r5 = s[0];

	// 右值引用给右值取别名
	int&& rr1 = 10;
	double&& rr2 = x + y;
	double&& rr3 = fmin(x, y);
	string&& rr4 = string("11111111");

	// 左值引用不能直接引用右值，但const左值可以引用右值
	const int& rx1 = 10;
	const double& rx2 = x + y;
	const double& rx3 = fmin(x, y);
	const string& rx4 = string("11111111");

	// 右值引用不能直接引用左值，但可以引用move(左值)
	int&& rrx1 = move(b);
	int*&& rrx2 = move(p);
	int&& rrx3 = move(*p);
	const int&& rrx4 = move(c);
	string&& rrx5 = move(s);
	char&& rrx6 = move(s[0]);
	

	// b, r1, rr1都是变量表达式，都是左值
	cout << &b << endl;
	cout << &r1 << endl;
	cout << &rr1 << endl;

	// 注意：rr1的属性是左值，所以不能再被右值引用绑定，除非move一下
	int& r6 = r1;
	//int&& rrx7 = rr1;
	int&& rrx7 = move(rr1);
}

void test05()
{
	string s1 = "Test";
	//string&& r1 = s1;		// 没有move的左值不能绑定到右值

	const string& s2 = s1 + s1;
	//s2 += "Test";			// const 不能修改

	string&& s3 = s1 + s1;
	cout << s3 << endl;

	s3 += "Test";			// 非const的右值可以被修改
	cout << s3 << endl;
}

void f(int& x)
{
	cout << "左值引用重载" << endl;
}

void f(const int& x)
{
	cout << "const左值引用重载" << endl;
}

void f(int&& x)
{
	cout << "右值引用重载" << endl;
}

void test06()
{
	int i1 = 1;
	const int i2 = 2;

	f(i1);			// 调用左值引用重载
	f(i2);			// 调用const左值引用重载
	f(3);			// 调用右值引用重载
	f(move(i1));	// 调用右值引用重载

	// 右值引用变量在于表达式时是左值
	int&& x = 1;
	f(x);			// 调用左值引用重载
	f(move(x));		// 调用右值引用重载
}

void test07()
{

}

int main()
{
	//tset01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();

	return 0;
}