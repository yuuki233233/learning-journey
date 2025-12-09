#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
 
namespace yuuki
{
	class string
	{
	public:
		//用迭代器时
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		// 方法1：
		//string()
		//	:_str(new char[1]{'\0'})
		//	,_size(0)
		//	,_capacity(0)
		//{ }

		//string(const char* str)
		//{
		//	_size = strlen(str);
		//	_capacity = _size;
		//	// _capacity不包含\0
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, str);
		//}

		// 方法2：合并成一个（缺省参数）
		string(const char* str = " ")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//s2(s1)
		string(const string& str)
		{
			_str = new char[str._capacity + 1];
			strcpy(_str, str._str);
			_size = str._size;
			_capacity = str._capacity;
		}

		//s2 = s1
		string& operator=(const string& str);

		~string()
		{
			delete[] _str;
			_str == nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t = npos);

		size_t find(char ch, size_t pos = 0);
		size_t find(char* str, size_t pos = 0);
		string substr(size_t pos = 0, size_t len = npos);
	private:
		char* _str;
		int _size;
		int _capacity;

		static const size_t npos;
	};

	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);

	void test_string1();
	void test_string2();
	void test_string3();
	void test_string4();
}