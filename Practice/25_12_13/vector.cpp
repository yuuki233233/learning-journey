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

void test_vector02()
{
	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.size() << endl;		//10
	cout << v.capacity() << endl;	//20

	v.reserve(15);
	cout << v.size() << endl;		//10
	cout << v.capacity() << endl;	//20

	v.reserve(5);
	cout << v.size() << endl;		//10
	cout << v.capacity() << endl;	//20
}

void test_vector03()
{
	vector<int> v1(10, 1);
	v1.reserve(20);
	cout << v1.size() << endl;		//10
	cout << v1.capacity() << endl;	//20

	v1.resize(15, 2);
	cout << v1.size() << endl;		//15
	cout << v1.capacity() << endl;	//20

	v1.resize(25, 3);				
	cout << v1.size() << endl;		//25
	cout << v1.capacity() << endl;	//30

	v1.resize(5);
	cout << v1.size() << endl;		//5
	cout << v1.capacity() << endl;	//30
}

void test_vector04()
{
	vector<int> v(5, 1);
	vector<vector<int>> vv(10, v);

	for (auto x : vv)
	{
		for (auto y : v)
		{
			cout << y << " ";
		}
		cout << endl;
	}

	/*for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < v.size(); ++j)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}*/
}

int main()
{
	//test_vector01();
	//test_vector02();
	//test_vector03();
	test_vector04();
	return 0;
}
