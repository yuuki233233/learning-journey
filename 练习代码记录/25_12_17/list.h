#pragma once
#include<iostream>
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

		list_node(const T& data = T()) // 匿名对象
			:_data(data)
			,_next(nullptr)
			,_prev(nullptr)
		{ }
	};

	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T> Self;
		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{ }

		T& operator*()
		{
			return _node->_data;
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

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};

	// 结构
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public: 
		typedef list_iterator<T> iterator;

		iterator begin()
		{
			/*iterator it(_head->_next); // 有名对象
			return it;*/

			//return iterator(_head->_next); // 匿名对象

			return _head->_next; // 隐式类型转换
		}

		iterator end()
		{
			return _head;
		}

		// 构造
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
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

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void erase(iterator pos)
		{
			assert(pos != end());

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			--_size;
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

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

	void test_list01()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int>::iterator it = lt1.begin();
		while (it != lt1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

}