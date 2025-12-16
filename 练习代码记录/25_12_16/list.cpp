#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

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
	cout << endl;
}

int main()
{
	test_list01();

	return 0;
}