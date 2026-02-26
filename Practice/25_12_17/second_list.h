#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace yuuki
{
	// 节点
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		// 拷贝构造
		list_node(const T& data = T()) // 匿名对象
			:_data(data)
			, _next(nullptr)
			, _prev(nullptr)
		{
		}
	};

	// 迭代器
	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		// 构造
		list_iterator(Node* node)
			:_node(node)
		{
		}

		// 解迭代器的引用 (*it)
		Ref operator*()
		{
			return _node->_data;
		}

		// 结构体箭头的重载 (it->_a1)
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};

	//// 迭代器
	//template<class T>
	//struct list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef list_const_iterator<T> Self;
	//	Node* _node;

	//	// 构造
	//	list_const_iterator(Node* node)
	//		:_node(node)
	//	{
	//	}

	//	// 解迭代器的引用 (*it)
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	// 结构体箭头的重载 (it->_a1)
	//	const T* operator->()
	//	{
	//		return &_node->_data;
	//	}

	//	Self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	Self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	Self operator++(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}

	//	Self operator--(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}

	//	bool operator!=(const Self& s) const
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const Self& s) const
	//	{
	//		return _node == s._node;
	//	}
	//};

	// 链表结构
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		 // 自己手动写(迭代器和const迭代器)
		/*typedef list_iterator<T> iterator;
		typedef list_const_iterator<T> const_iterator;*/

		// 编译器自己实例化两个不同的类
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		// 头为哨兵位前一个节点
		iterator begin()
		{
			/*iterator it(_head->_next); // 有名对象
			return it;*/

			//return iterator(_head->_next); // 匿名对象

			return _head->_next; // 隐式类型转换
		}

		// 尾为哨兵位
		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		// 构造
		list()
		{
			empty_init();
		}

		list(initializer_list<T> il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		// lt2(lt1)
		list(const list<T>& lt)
		{
			// 哨兵位头节点
			empty_init();

			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		// lt1 = lt3
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		// 尾插
		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			++_size;*/

			insert(end(), x);
		}

		// 头插
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		//// 删除指定迭代器的位置
		//void erase(iterator pos)
		//{
		//	assert(pos != end());

		//	Node* prev = pos._node->_prev;
		//	Node* next = pos._node->_next;

		//	prev->_next = next;
		//	next->_prev = prev;
		//	delete pos._node;
		//	--_size;
		//}

		// 删除指定迭代器的位置
		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;

			return next; // 隐式类型转换
		}

		// 尾删
		void pop_back()
		{
			erase(--end());
		}

		// 头删
		void pop_front()
		{
			erase(begin());
		}

		// 固定位置插入
		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);

			// prev newnode cur
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;

			++_size;
		}

		size_t size() const
		{
			return _size;
		}

		bool empty() const
		{
			//return _head->next == _head;
			return _size == 0;
		}

	private:
		Node* _head;
		size_t _size;
	};

	struct AA
	{
		int _a1 = 1;
		int _a2 = 1;
	};

	// 支持所有容器
	// 按需实例化
	template<class Container>
	void print_container(const Container& v)
	{
		// const iterator -> 迭代器本身不能修改
		// const_iterator -> 指向内容不能修改

		//list<int>::const_iterator it = v.const_begin();
		auto it = v.begin();
		while (it != v.begin())
		{
			// const迭代器只读不写
			//*it += 10; 
			cout << *it << " ";
			++it;
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list01()
	{
		// 单类型
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int>::iterator it = lt1.begin();
		while (it != lt1.end())
		{
			// const迭代器不能修改
			// *it += 10;

			// 普通迭代器可以修改
			*it += 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		// 结构体
		list<AA> lta;
		lta.push_back(AA());
		lta.push_back(AA());
		lta.push_back(AA());
		lta.push_back(AA());
		list<AA>::iterator ita = lta.begin();
		while (ita != lta.end())
		{
			//cout << (*ita)._a1 << ":" << (*ita)._a2;
			// 特殊处理，本来应该是两个(->)才合理，为了可读性，省略了一个(->)
			cout << (ita.operator->())->_a1 << ":" << ita->_a2 << "  ";
			++ita;
		}
		cout << endl;

		print_container(lt1);
	}

	void test_list02()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		// insert以后迭代器不失效
		list<int>::iterator it = lt.begin();
		lt.insert(it, 20);
		*it += 100;			// 输出： 20 101 2 3 4 (迭代器没有失效)
		print_container(lt);

		// erase以后迭代器失效
		// 删除所有的偶数
		it = lt.begin();
		while (it != lt.end())
		{
			if (*it % 2 == 0)
			{
				//lt.erase(it); // 迭代器失效
				it = lt.erase(it);
			}
			else
			{
				++it;
			}
		}

		print_container(lt);
	}

	void test_list03()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int> lt2(lt1);

		print_container(lt1);
		print_container(lt2);


		list<int> lt3;
		lt3.push_back(10);
		lt3.push_back(20);
		lt3.push_back(30);
		lt3.push_back(40);

		lt1 = lt3; // 默认生成浅拷贝
		print_container(lt1);
		print_container(lt3);
	}

	void func(const list<int>& lt)
	{
		print_container(lt);
	}

	void test_list04()
	{
		// 隐式类型转换
		list<int> lt1 = { 1, 2, 3, 4, 5, 6 };
		// 直接构造(C++11)
		list<int> lt2({ 1,2,3,4,5,6 });
		const list<int>& lt3 = { 1,2,3,4,5,6 };

		func(lt1);
		func({ 1,2,3,4,5,6 });

		initializer_list<int> il = { 10, 20, 30 };
		cout << typeid(il).name() << endl;
		cout << sizeof(il) << endl;		// 输出：8 (证明有两个指针分别指向头和尾)

	}
}