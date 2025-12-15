#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace yuuki
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		const_iterator begin() const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator end() const
		{
			return _finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_stor - _start;
		}

		T& operator[](size_t i)
		{
			assert(i < size());

			return _start[i];
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());

			return _start[i];
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				int old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * size());
				delete[] _start;

				_start = tmp;
				_finish = tmp + old_size;
				_end_of_stor = tmp + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_stor)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;
			++_finish;
		}

		void insert(iterator pos, const T& x)
		{
			if (_finish == _end_of_stor)
			{
				//解决迭代器失效
				size_t old_pos = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + old_pos;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
		}

		bool empty()
		{
			return _start == _finish;
		}

		void pop_back()
		{
			assert(!empty());

			--_finish;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_stor = nullptr;
	};

	template<class T>
	void print_vector(const vector<T>& v)
	{
		for (auto E : v)
		{
			cout << E << " ";
		}
		cout << endl;
	}

	/*void print_vector(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}*//*void print_vector(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}*/

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);

		print_vector(v);

		vector<double> vd;
		vd.push_back(1.1);
		vd.push_back(1.2);
		vd.push_back(1.3);
		vd.push_back(1.4);
		vd.push_back(1.5);

		print_vector(vd);
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.insert(v.begin() + 3, 30);
		v.push_back(4);
		print_vector(v);

		int x;
		cin >> x;
		auto p = find(v.begin(), v.end(), x);
		if (p != v.end())
		{
			// insert以后p就是失效，不要直接访问，要访问就要更新这个失效的迭代器的值
			v.insert(p, 40);
			(*p) *= 10;
		}
		print_vector(v);

	}
}