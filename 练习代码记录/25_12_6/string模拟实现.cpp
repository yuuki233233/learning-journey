#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace yuuki
{
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new  char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		
	}

	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	/*string& string::operator+=(const char* str)
	{
		
	}*/

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
		s1 += 'x';
		s1 += '#';
		cout << s1.c_str() << endl;
	}
}