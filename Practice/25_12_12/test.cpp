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
	s1.operator+=('#');
	cout << s1.c_str() << endl;

	s2.append("%%%%%%%%%%");
	cout << s2.c_str() << endl;
	s2.operator+=("##########");
	cout << s2.c_str() << endl;

	cout << s1[4] << endl;
	cout << s2[0] << endl;
}

void test_string02()
{
	string s1("hello world");
	string s2("hello yuuki");

	s1.insert(0, "x");
	cout << s1.c_str() << endl;

	s2.insert(0, "xxxxxx");
	cout << s2.c_str() << endl;

	s1.erase(0, 10);
	cout << s1.c_str() << endl;

	s2.erase(0, 10);
	cout << s2.c_str() << endl;
}

void test_string03()
{
	string s1("hello world");
	string s2("hello yuuki");

	cout << (s1 < s2) << endl;
	cout << (s1 <= s2) << endl;

	cin >> s1 >> s2;
	cout << s1.c_str() << s2.c_str() << endl;
}

int main()
{
	//test_string01();
	//test_string02();
	test_string03();

	return 0;
}