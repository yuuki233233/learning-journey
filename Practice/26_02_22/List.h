#pragma once
#include<assert.h>

//#include"Iterator.h"

namespace yuuki
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		//list_node(const T& data = T())
		//	:_data(data)
		//	,_next(nullptr)
		//	,_prev(nullptr)
		//{ }

		//list_node(T&& data)
		//	:_data(forward<T>(data))
		//	,_next(nullptr)
		//	,_prev(nullptr)
		//{ }

		list_node() = default;

	/*	template<class X>
		list_node(X&& data)
			:_data(forward<X>(data))
			,_next(nullptr)
			,_prev(nullptr)
		{ }*/

		template <class... Args>
		list_node(Args&&... args)
			: _next(nullptr)
			, _prev(nullptr)
			, _data(std::forward<Args>(args)...)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{
		}

		Ref operator*()
		{
			return _node->_data;
		}

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

		Self& operator--(int)
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


	/*template<class T>
	struct list_const_iterator
	{
		typedef list_node<T> Node;
		typedef list_const_iterator<T> Self;
		Node* _node;

		list_const_iterator(Node* node)
			:_node(node)
		{}

		const T& operator*()
		{
			return _node->_data;
		}

		const T* operator->()
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

		Self& operator--(int)
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
	};*/

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		/*typedef list_iterator<T> iterator;
		typedef list_const_iterator<T> const_iterator;*/

		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		//typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		//typedef ReverseIterator<const_iterator, const T&, const T*> const_reverse_iterator;

		//reverse_iterator rbegin()
		//{
		//	return reverse_iterator(--end());
		//}

		//reverse_iterator rend()
		//{
		//	return reverse_iterator(end());
		//}

		// 对称
	/*	reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}*/

		iterator begin()
		{
			return _head->_next;
		}

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

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

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

		// lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();

			for (auto& e : lt)
			{
				push_back(e);
			}
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

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_back(T&& x)
		{
			insert(end(), forward<T>(x));
		}

		/* 不能隐式类型转换，因为不确定 X 是  pair类型 */
		// 万能引用
		/*template<class X>
		void push_back(X&& x)
		{
			insert(end(), forward<X>(x));
		}*/

		/* 可变参数模板 */
		template<class... Args>
		void emplace_back(Args&&... args)
		{
			/* 实践中不需要包扩展，除非要看打印 */
			insert(end(), forward<Args>(args)...);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		//iterator insert(iterator pos, const T& x)
		//{
		//	Node* cur = pos._node;
		//	Node* prev = cur->_prev;
		//	Node* newnode = new Node(x);

		//	// prev newnode cur
		//	newnode->_next = cur;
		//	cur->_prev = newnode;
		//	newnode->_prev = prev;
		//	prev->_next = newnode;

		//	++_size;

		//	return newnode;
		//}

		//iterator insert(iterator pos, T&& x)
		//{
		//	Node* cur = pos._node;
		//	Node* prev = cur->_prev;
		//	Node* newnode = new Node(forward<T>(x));

		//	// prev newnode cur
		//	newnode->_next = cur;
		//	cur->_prev = newnode;
		//	newnode->_prev = prev;
		//	prev->_next = newnode;

		//	++_size;

		//	return newnode;
		//}

		/* 万能引用 */
		template<class X>
		iterator insert(iterator pos, X&& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(forward<T>(x));

			// prev newnode cur
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;

			++_size;

			return newnode;
		}

		/* 可变参数模板 */
		template<class... Args>
		iterator insert(iterator pos, Args&&... args)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			/* 也就把参数包往下传即可 */
			Node* newnode = new Node(forward<Args>(args)...);

			// prev newnode cur
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;

			return iterator(newnode);
		}

		//template<class X>
		//iterator insert(iterator pos, X&& x)
		//{
		//	Node* cur = pos._node;
		//	Node* prev = cur->_prev;
		//	Node* newnode = new Node(forward<X>(x));

		//	// prev newnode cur
		//	newnode->_next = cur;
		//	cur->_prev = newnode;
		//	newnode->_prev = prev;
		//	prev->_next = newnode;

		//	++_size;

		//	return newnode;
		//}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;

			--_size;

			return next;
		}

		size_t size() const
		{
			return _size;
		}

		bool empty() const
		{
			return _size == 0;
		}
	private:
		Node* _head;
		size_t _size;
	};
}