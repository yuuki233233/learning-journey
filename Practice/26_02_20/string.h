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

			cout << " string() -- 构造" << endl;
		}

		//s2(s1)
		string(const string& str)
		{
			_str = new char[str._capacity + 1];
			strcpy(_str, str._str);
			_size = str._size;
			_capacity = str._capacity;

			cout << " string(const string & str) -- 拷贝构造" << endl;
		}

		/*string(string&& str)
		{
			cout << "string(string&& str) -- 移动构造" << endl;
			swap(str);
		}*/

		//s2 = s1
		string& operator=(const string& str)
		{
			// s1 = s1(深拷贝)
			if (this != &str)
			{
				delete[] _str;
				_str = new char[str._capacity + 1];
				strcpy(_str, str._str);
				_size = str._size;
				_capacity = str._capacity;
			}
			cout << " string& operator=(const string& str) -- 赋值重载" << endl;

			return *this;
		}

		void swap(string& str)
		{
			swap(str);
		}

		/*string& operator=(string&& str)
		{
			cout << "string& operator=(string&& str) -- 移动赋值" << endl;
			swap(str);
			return *this;
		}*/

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

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
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

	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
}