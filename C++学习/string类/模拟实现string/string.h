#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace yuuki
{
	class string
	{
	public:
		typedef char* iterator;
		const typedef char* const_iterator;

		string(const char* str = " ")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;	
			}
		}

		const char* c_str() const
		{
			return _str;
		}

		int size()
		{
			return _size;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		char& operator[](int n)
		{
			return _str[n];
		}

		void reserve(size_t n);
		void push_back(char ch);
		string& operator+=(char ch);
		void append(char* str);
		string& operator+=(char* str);

		void insert(char ch);
		void insert(char* str);

	private:
		char* _str;
		int _size;
		int _capacity;
	};

	void test_string1();
	void test_string2();
}