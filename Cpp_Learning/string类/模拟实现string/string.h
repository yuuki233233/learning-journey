#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace yuuki233233
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		const_iterator begin() const
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string()
			:_str(new char[1] {'\0'})
			, _size(0)
			, _capacity(0)
		{
		}

		string(const char* str)
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const;
		size_t capacity() const;


		char& operator[](size_t pos);
		const char& operator[](size_t pos) const;

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

	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
}