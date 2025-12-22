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

void test_list03() //insert find erase
{
	// ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
	// insert
	list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
	li.push_back(4);

	//li.insert(li.begin() + 2, 30); //不支持【begin()+num】
	li.insert(li.begin(), 30);
	print(li);

	//如果偏要在某位置插入，则需要用迭代器找位置
	auto it = li.begin();
	int n = 2;
	while (n--)
	{
		it++;
	}
	li.insert(it, 60);
	print(li);
	// ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ 


	// ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
	//find erase

	int x = 0;
	cin >> x;
	it = find(li.begin(), li.end(), x);
	if (it != li.end())
	{
		li.erase(it);
	}
	print(li);
	// ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ 

}

void test_list04() //list中的sort
{
	// 由于算法库中的sort对list不友好，所以单独为list开了个排序
	list<int> li;
	li.push_back(10);
	li.push_back(2);
	li.push_back(100);
	li.push_back(6);
	li.push_back(30);
	li.push_back(9);
	print(li);

	// 默认升序
	li.sort();
	print(li);

	// 降序 - 仿函数
	// 有名对象
	//greater<int> gt;
	//li.sort(gt);

	// 匿名对象(一次性，更方便)
	li.sort(greater<int>());
	print(li);
}

void test_list05() //unique
{
	list<int> li;
	li.push_back(6);
	li.push_back(3);
	li.push_back(1);
	li.push_back(6);
	li.push_back(6);
	li.push_back(8);
	print(li);
	//li.unique(); // 必须先排序，后删除
	//print(li); // 6 3 1 6 8

	li.sort();
	li.unique();
	print(li); // 1 3 6 8

}

void test1()
{
	list<int> l1; // 无参构造：创建空list

	list<int> l2(10, 1); // 构造并初始化10个1

	list<int> l3(l2.begin(), l2.end()); // 迭代器区间构造
	print(l3);

	print(l3);
	// 在链表中不适用 (l2.begin()+3);
	//list<int> l3(l2.begin() + 3, l2.end());
	
}

void test_list06() // splice(剪切数据)
{
	list<int> l1, l2;

	for (size_t i = 1; i < 4; ++i)
	{
		l1.push_back(i); // 输出：1 2 3
	}

	for (size_t i = 1; i < 4; ++i)
	{
		l2.push_back(i * 10);// 输出：10 20 30
	}

	list<int>::iterator it = l1.begin(); // 迭代器的指向位置

	l1.splice(it, l2); // 输出：10 20 30 1 2 3
						// l2--->nullptr
}

int main()
{
	test_list06();

	return 0;
}