#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> lt{ 1,2,3,4,5 };
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;

	//赋值，自动迭代，自动判断结束(底层还是迭代器)
	for (auto li : lt)
	{
		cout << li << " ";
	}
	cout << endl;

	return 0;
}