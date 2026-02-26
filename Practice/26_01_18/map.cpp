#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdbool.h>
#include<map>
#include<set>

void set01() // set插入、打印
{
	// 内置类型
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);

	/*for (auto e : s)
		cout << e << " ";*/

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 1; set不支持修改
		cout << *it << " ";
		it++;
	} // 1 2 3
	cout << endl;

	// C++11写法(可连续插入多个数据)
	s.insert({ 4, 5, 6 });
	for (auto e : s)
		cout << e << " ";
	cout << endl;

	// 外置类型
	set<string> str;
	str.insert({ "hello"," ", "world" });
	for (auto e : str)
		cout << e << " ";
	cout << endl;
}

void set02() // 删除
{
	set<int> s({ 1, 2, 3 });
	for (auto e : s)
		cout << e << " "; // 1 2 3
	cout << endl;

	// erase删除(只支持头删)
	s.erase(s.begin());
	for (auto e : s)
		cout << e << " "; // 2 3
	cout << endl;

	//s.erase(s.end()); // 尾删报错
	//for (auto e : s)
	//	cout << e << " ";
	//cout << endl;

	int era = s.erase(2); // erase删除返回整形
	for (auto e : s)
		cout << e << " "; // 2 3
	cout << endl;
	if (era == 0) // 删除失败返回0
	{
		cout << "删除失败" << endl;
	}
	else // 成功返回非0
	{
		cout << "删除成功" << endl;
	}
}

void set03() // 查找
{
	set<int> s({ 1, 2, 3, 4, 5, 6 });
	for (auto e : s)
	{
		cout << e << " "; // 1 2 3 4 5 6
	}
	cout << endl;

	// 直接查找在利⽤迭代器删除x
	auto e = s.find(3); // 查找到返回迭代器
	if (e != s.end())
	{
		s.erase(e); // 删除迭代器上的数据，后迭代器失效
	}
	for (auto e : s)
	{
		cout << e << " "; // 1 2 4 5 6
	}
	cout << endl;

	int x;
	cin >> x;
	// 利⽤count间接实现快速查找
	if (s.count(x))
	{
		cout << "存在" << endl;
	}
	else
	{
		cout << "不存在" << endl;
	}

	// 算法库的查找 O(N)
	auto pos1 = find(s.begin(), s.end(), x);
	// set⾃⾝实现的查找 O(logN)
	auto pos2 = s.find(x);
}

void set04() // 区间删除
{
	set<int> s({ 1, 2, 3, 4, 5, 6, 7 });
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 实现查找到的[itlow,itup)包含[2, 6]区间
	// 返回 >= 2
	auto itlow = s.lower_bound(2);
	// 返回 > 6
	auto itup = s.upper_bound(6);

	// 删除这段区间的值
	s.erase(itlow, itup);
	for (auto e : s)
	{
		cout << e << " "; // 1 6 7
	}
}

void set05() // multiset set
{
	// 相比set不同的是，multiset是排序，但是不去重
	multiset<int> s = { 4,2,7,2,4,8,4,5,4,9 };
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 相⽐set不同的是，x可能会存在多个，find查找中序的第⼀个
	int x;
	cin >> x;
	auto pos = s.find(x);
	while (pos != s.end())
	{
		if (*pos == x)
		{
			cout << *pos << " ";
		}
		++pos;
	}
	cout << endl;

	// 相⽐set不同的是，count会返回x的实际个数
	cout << s.count(x) << endl;

	// 相⽐set不同的是，erase给值时会删除所有的x
	s.erase(x);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//set01();
	//set02();
	//set03();
	//set04();
	set05();
	return 0;
}