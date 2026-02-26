#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	//C++98遍历
	int array1[] = { 1,2,3,4,5 };
	for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
	{
		array1[i] *= 2;
	}
	for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
	{
		cout << array1[i] << " ";
	}
	cout << endl;


	//C++11遍历(auto自动识别类型)
	int array2[] = { 1,2,3,4,5 };
	for (auto& e : array2)
		e *= 2;

	for (auto& e : array2)
		cout << e << " ";
	cout << endl;

	string str("hello world");
	for (auto ch : str)
	{
		cout << ch << " ";
	}
	cout << endl;

	return 0;
}