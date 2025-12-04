#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void Test01()
{
	//直接构造字符串
	string s1("hello world");
	cout << s1 << endl << endl;

	//修改指定的单个字符
	s1[0] = 'x';
	cout << s1 << endl << endl;

	//修改整个字符
	for (int i = 0; i < s1.size(); i++)
		cin >> s1[i];
	cout << s1 << endl << endl;
}

void Test02()
{
	string s1("hello world");

	for (auto it = s1.begin(); it != s1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Test03()
{
	string s1("hello world");

	// 使用反向迭代器遍历字符串
	for (auto it = s1.rbegin(); it != s1.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	Test01();
	Test02();
	Test03();

	return 0;
}