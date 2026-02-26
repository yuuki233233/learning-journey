#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace yuuki
{
	void test_string1()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.size(); ++i)
		{
			s2[i] += 2;
		}
		cout << s2.c_str() << endl;

		for (auto e : s2)
		{
			cout << e << " ";
		}
		cout << endl;

		//char* it = s2.begin();
		string::iterator it = s2.begin();
		while (it != s2.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		//运算符重载单字符
		s1 += 'x';
		s1 += '#';
		cout << s1.c_str() << endl;

		//运算符重载字符串
		s1 += "hello yuuki";
		cout << s1.c_str() << endl;

		//插入单字符
		s1.insert(0, '$');
		cout << s1.c_str() << endl;

		//插入字符串
		s1.insert(6, "######");
		cout << s1.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		s1.erase(6, 100);
		cout << s1.c_str() << endl;

		string s2("hello world");
		s2.erase(6);
		cout << s2.c_str() << endl;

		string s3("hello world");
		s3.erase(6, 3);
		cout << s3.c_str() << endl;

		string s4("hello world");
		s4.erase(2, 1);
		cout << s4.c_str() << endl;
	}

	void test_string4()
	{
		string s1("test.cpp.zip");
		size_t pos = s1.find('.');
		//编译器优化(substr中申请了空间并返回)
		//检测编译器优化，如果编译器不优化会释放同一个空间
		string suffix = s1.substr(pos);
		cout << suffix.c_str() << endl;

		//拷贝构造
		string s2(s1);
		cout << s2.c_str() << endl;

		//默认调用浅拷贝，会导致内存泄漏
		s1 = s2;
		cout << s2.c_str() << endl;
		cout << s1.c_str() << endl;

		s1 = s1;
		cout << s1.c_str() << endl;
	}

	void test_string5()
	{
		string s1("hello world");
		string s2("hello world");

		cout << (s1 < s2) << endl;	//0
		cout << (s1 <= s2) << endl;	//1

		//隐式类型转化成string
		cout << (s1 < "hello world") << endl;	//0
		cout << ("hello world" <= s2) << endl;	//1

		//运算符重载必须有个类类型的参数才能用隐式比较
		//cout << ("hello world" == "hello world") << endl;

	}

	void test_string6()
	{
		string s1("hello");
		string s2("world");
		cout << s1 << s2 << endl;

		string ss1;
		cin >> ss1;
		cout << ss1 << endl;
	}
}

int main()
{
	// yuuki::test_string1(); 
	//yuuki::test_string2();
	// yuuki::test_string3();
	//yuuki::test_string4();
	//yuuki::test_string5();
	yuuki::test_string6();

	return 0;
}