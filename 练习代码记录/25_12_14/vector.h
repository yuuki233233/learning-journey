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

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
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
			return _end_of_storage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, size() * sizeof(T));

				delete[] _start;
				_start = tmp;
				//-----------------------------------
				//_finish = _start + size();	//size为新的，需要旧的size
				_finish = tmp + old_size;
				_end_of_storage = _start + n;
			}
		}

		// 存在限制，用double类型则调用不了，可以考虑用模板
		/*void print_vector(const vector<int>& v)
		{
			for (size_t i = 0; i < v.size(); ++i)
			{
				cout << v[i] << " ";
			}
			cout << endl;

			vector<int>::const_iterator it = v.begin();
			while (it != v.end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;

			for (auto E : v)
			{
				cout << E << " ";
			}
			cout << endl;
		}*/

		template<class T>
		void print_vector(const vector<T>& v)
		{
			// 规定，没有实例化的类模板里面取东西，编译器不能区分这里const_iterator
			// 是类型还是静态成员变量
			//typename vector<T>::const_iterator it = v.begin();
			auto it = v.begin();

			while (it != v.end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;

			for (auto E : v)
			{
				cout << E << " ";
			}
			cout << endl;
		}

		void push_back(char ch)
		{
			if (_start == _finish)
			{
				reserve(capacity() == 0 ? 4 : capacity()* 2);
			}

			*_finish = ch;
			++_finish;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		

		

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		v.print_vector(v);

		vector<double> vd;
		v.push_back(1.1);
		v.push_back(2.2);
		v.push_back(3.3);
		v.push_back(4.4);
		v.push_back(5.5);
		
		vd.print_vector(vd);
	}
}