#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void test_vector01()
{
	vector<int> v1;
	vector<int> v2(10, 1);

	vector<int> v3(++v2.begin(), --v2.end());

	for (int i = 0; i < v2.size(); ++i)
	{
		cout << v2[i];
	}
	cout << endl;

	for (auto x : v2)
	{
		cout << x;
	}
	cout << endl;

	vector<int>::iterator it = v2.begin();
	while (it != v2.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

int main()
{
	test_vector01();

	return 0;
}