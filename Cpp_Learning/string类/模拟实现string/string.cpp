#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace yuuki233233
{
	const size_t string::npos = -1;

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			string s1("hello world");
			string s2("hello yuuki");
			char* tmp = new char[n + 1];
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
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len > _capacity * 2 ? _size + len : _capacity * 2);
		}

		strcpy(_str + _size, str);
		_size += len;
	}

	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	size_t string::size() const
	{
		return _size;
	}

	size_t string::capacity() const
	{
		return _capacity;
	}

	char& string::operator[](size_t pos)
	{
		assert(pos < _size);

		return _str[pos];
	}

	const char& string::operator[](size_t pos) const
	{
		assert(pos < _size);

		return _str[pos];
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos < _size);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}

		_str[pos] = ch;
		++_size;
	}

	void string::insert(size_t pos, const char* str)
	{
		assert(pos < _size);

		int len = strlen(str);
		size_t end = _size + len;
		if (end > _capacity * 2)
		{
			reserve(end > _capacity * 2 ? end : _capacity * 2);
		}
		while (end > pos)
		{
			_str[end] = _str[end - pos];
			--end;
		}
		for (int i = 0; i < len; i++)
		{
			_str[len + i] = _str[len + i + 1];
		}
	}

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
		assert(pos < _size);

		for (int i = 0; i < _size; ++i)
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

	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);

		if (len > _size - pos)
		{
			len = _size - pos;
		}

		string sub;
		sub.reserve(len);
		for (size_t i = 0; i < len; ++i)
		{
			sub += _str[pos + i];
		}

		return sub;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto x : s)
		{
			out << x;
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		in.clear();

		char ch;
		ch = in.get();

		while (ch != ' ' && ch != '\0')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}
}