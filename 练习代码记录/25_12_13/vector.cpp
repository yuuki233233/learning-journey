#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace yuuki
{
	class string
	{
	public:
		string(const char* str = " ")
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

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}

		string(const string& s)
		{
			string tmp(s._str);
			swap(tmp);
		}

		//中间变量
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				swap(tmp);
			}
			return *this;
		}

		//直接交换
		string& operator=(string tmp)
		{
			swap(tmp);
			return *this;
		}

	private:
		char* _str;
		int _size;
		int _capacity;
	};

}


int main()
{
	
	return 0;
}