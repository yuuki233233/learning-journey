#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

template<class T>
void print(const T& t)
{
	auto it = t.begin();
	while (it != t.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list01()
{
	list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
	li.push_back(4);

	list<int>::iterator it = li.begin();
	while (it != li.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : li)
	{
		cout << e << " ";
	}
	cout << endl << endl;

	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(2);
	v.push_back(1);
	print(v); // 3 4 2 1

	// ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
	
	//sort(li.being(), li.end()) //sort()要求随机迭代器
	sort(v.begin(), v.end()); 
	print(v); // 1 2 3 4

	string s("helloworld");
	sort(s.begin(), s.end());
	cout << s << endl; // dehllloorw

	// ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ 
}

struct A
{
public:
	A(int a = 1, int b = 1)
		:_a(a)
		,_b(b)
	{
		cout << "a(int a = 1, int b = 1)" << endl;
	}

	A(const A& aa)
		:_a(aa._a)
		,_b(aa._b)
	{
		cout << "A(const A& aa)" << endl;
	}

private:
	int _a;
	int _b;
};
void test_list02() //emplace与push差别
{
	//单变量
	list<int> li;
	li.emplace_back(1);
	li.emplace_back(2);
	li.emplace_back(3);
	li.emplace_back(4);
	print(li);

	//双变量
	list<A> lt;
	A aa1(1, 1);
	lt.push_back(aa1);
	lt.push_back(A(1, 1));
	//lt.push_back(1, 1); //不支持直接传构造A的参数

	lt.emplace_back(aa1);
	lt.emplace_back(A(1, 1));
	cout << endl;

	lt.emplace_back(1, 1); //支持直接传构造A的参数

}

int main()
{
	test_list02();

	return 0;
}