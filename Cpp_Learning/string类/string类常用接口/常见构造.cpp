#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	//构造空的string类对象，即空字符串
	string s1;

	//用C-string来构造string类对象
	string s2("hello world");

	//拷贝构造函数
	string s3(s2);
	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	return 0;
}