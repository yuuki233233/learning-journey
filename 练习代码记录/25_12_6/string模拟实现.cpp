#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace yuuki
{
	const size_t string::npos = -1;

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
		//别忘了加'\0'
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			//需要多少扩多少
			//reserve(_size + len);

			//二倍扩容（避免频繁扩容）
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}

		strcpy(_str + _size, str);
		_size += len;
	}

	//单字符
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	//字符串（不能按二倍扩容）
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}


	//插入字符
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);

		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		/*
		方法1：

		//挪动数据
		int end = _size;
		//隐式类型转化<---pos(size_t)===end(int)
		//当end为-1时，因为pos为无符号，end会转化为无符号进行比较
		while (end >= (int)pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}

		*/

		//方法2：
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}


		_str[pos] = ch;
		++_size;
	}

	//插入字符串
	void string::insert(size_t pos, const char* str)
	{
		assert(pos < _size);

		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			//二倍扩容（避免频繁扩容）
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}

		size_t end = _size + len;
		//注意：使用pos+len会出现问题
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}

		for (size_t i = 0; i < len; ++i)
		{
			_str[pos + i] = str[i];
		}
	}

	//删除
	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);

		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			for (size_t i = pos + len; i < _size; ++i)
			{
				_str[i] = _str[i + len];
			}
			_size -= len;
		}
	}

	size_t string::find(char ch, size_t pos)
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}

		return npos;
	}

	size_t string::find(char* str, size_t pos)
	{
		assert(pos < _size);

		const char* tmp = strstr(_str + pos, str);
		if (tmp == nullptr)
		{
			return npos;
		}
		else
		{
			return tmp - _str;
		}
	}

	

	
}