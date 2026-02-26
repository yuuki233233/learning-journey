#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1("hello world");

	//正向迭代器
	//string::iterator it = s1.begin();
	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//反向迭代器
	//string::reverse_iterator rit = s1.rbegin();
	auto rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	const string s2("hello world");
	//const正向迭代器
	//string::const_iterator cit = s2.begin();
	auto cit = s2.begin();
	while (cit != s2.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	//const反向迭代器
	//string::const_reverse_iterator rcit = s2.rbegin();
	auto rcit = s2.rbegin();
	while (rcit != s2.rend())
	{
		cout << *rcit << " ";
		++rcit;
	}

	return 0;
}