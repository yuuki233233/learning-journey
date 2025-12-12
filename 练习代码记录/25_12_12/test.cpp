#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

void test_string01()
{
	string s1("hello world");
	string s2("hello yuuki");
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	s1.push_back('%');
	cout << s1.c_str() << endl;

	s2.append("%%%%%%%%%%");
	cout << s2.c_str() << endl;

	cout << s1[4] << endl;
	cout << s2[0] << endl;
}

int main()
{
	test_string01();

	return 0;
}