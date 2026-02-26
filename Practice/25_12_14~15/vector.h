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

		/*vector()		
		{}*/

		// C++11 前置生成默认构造
		vector() = default;

		// v2(*this) = v1
		vector(const vector<T>& v)
		{
			reserve(size());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		void clear()
		{
			_finish = _start;
		}

		// v2 = v1 (传统写法)
		//vector operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		//this
		//		clear();
		//		reserve(v.size());
		//		for (auto& e : v)
		//		{
		//			push_back(e);
		//		}
		//	}

		//	return *this;
		//}

		// v2 = v1 (现代写法)
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector<T> operator=(vector<T> v)
		{
			swap(v);

			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

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
				_end_of_storage = tmp + n;
			}
		}

		void push_back(T ch)
		{
			if (_start == _finish)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = ch;
			++_finish;
		}
		
		bool empty()
		{
			return _finish == _start;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		//用迭代器实现
		void insert(iterator pos, const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start; //当插入时扩容，迭代器会失效(pos指向旧空间)
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
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

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);

			iterator it = pos + 1;
			while (it < end())
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;
			return pos; // 返回删除后的位置
		}
		
		//三种情况
		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

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

		/*for (auto E : v)
		{
			cout << E << " ";
		}
		cout << endl;*/
	}

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
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

		print_vector(v);

		vector<double> vd;
		vd.push_back(1.1);
		vd.push_back(2.2);
		vd.push_back(3.3);
		vd.push_back(4.4);
		vd.push_back(5.5);
		
		print_vector(vd);
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		print_vector(v);

		v.insert(v.begin(), 30);
		print_vector(v);

		int x;
		cin >> x;
		auto p = find(v.begin(), v.end(), x);
		if (p != v.end())
		{
			// insert以后p就是失效，不要直接访问，要访问就要更新这个失效的迭代器的值
			v.insert(p, 40);
			//(*p) *= 10;
		}
		print_vector(v);
	}

	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.insert(v.begin() + 2, 20);
		print_vector(v);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}
		print_vector(v);
	}

	void test_vector4()
	{
		vector<int> v;
		v.resize(10, 1);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(15, 2);
		print_vector(v);

		v.resize(25, 3);
		print_vector(v);

		v.resize(5);
		print_vector(v);
		
		vector<int> v2 = v;

		cout << endl;

		vector<int> v3;
		v3.push_back(10);
		v3.push_back(20);
		v3.push_back(30);

		v = v3;
		print_vector(v);
	}
}
