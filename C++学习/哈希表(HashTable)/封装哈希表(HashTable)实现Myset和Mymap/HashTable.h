#pragma once
#include<vector>
#include<iostream>
using namespace std;

enum State
{
	EXIST,
	EMPTY,
	DELETE
};


template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 131;
		}

		return hash;
	}
};

inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] = {
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}

template<class T>
struct HashNode
{
	T _data;
	HashNode<T>* _next;

	HashNode(const T& data)
		:_data(data)
		, _next(nullptr)
	{
	}
};

/*前置声明，告诉告诉编译器，HashTables 是个类模板*/
template<class K, class T, class KeyOfT, class Hash>
class HashTable;

template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
struct HTIterator
{
	typedef HashNode<T> Node;
	/*前后依赖，HashTable 在 HTIterator 的后面，编译器是向上找，导致编译器找不到*/
	typedef HashTable<K, T, KeyOfT, Hash> HT;
	typedef HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;

	Node* _node;
	HT* _ht;

	HTIterator(Node* node, HT* ht)
		:_node(node)
		,_ht(ht)
	{ }

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	Self& operator++()
	{
		/*
		* 迭代器++可分为3种情况
		* 1. 前桶有数据，走到下一个桶
		* 2. 前桶无数据，找 _node 所在位置，遍历直到找到有数据的桶为止
		*/
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			KeyOfT kot;
			Hash hash;
			/*这里的 _tables 是私有的，需要访问*/
			size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();
			++hashi;
			/*这里分为两种情况:1. hashi 还在桶内 2. hashi 已经在桶外*/
			while (hashi < _ht->_tables.size())
			{
				_node = _ht->_tables[hashi];
				if (_node)
					break;
				else
					++hashi;
			}

			if (hashi == _ht->_tables.size())
			{
				/*因为 end() 也是为nullptr，当 begin() 遍历完桶，begin() == end()*/
				_node = nullptr;
			}

			return *this;
		}
	}

	Self& operator--()
	{

	}
};

template<class K, class T, class KeyOfT, class Hash = HashFunc<K>>
class HashTable
{
	/*vetor 依赖 operator++，因为 _tables 是私有，访问不到，需要迭代器友元类*/
	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	friend struct HTIterator;

	typedef HashNode<T> Node;
public:
	typedef HTIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;
	typedef HTIterator<K, T, const T&, const T*, KeyOfT, Hash> ConstIterator;

	Iterator begin()
	{
		/*哈希表一开始开了53个空间，就会导致哈希表是空的，遍历时会把53个NULL遍历一遍，再 begin() = nullptr*/
		for (size_t i = 0; i <  _tables.size(); ++i)
		{
			if (_n == 0)
				return end();

			Node* cur = _tables[i];
			if (cur)
			{
				return Iterator(cur, this);
			}
		}
	}

	Iterator end()
	{
		return Iterator(nullptr, this);
	}

	HashTable()
		:_tables(__stl_next_prime(0))
		, _n(0)
	{
	}

	// 拷贝构造和赋值重载也需要

	~HashTable()
	{
		for (size_t i = 0; i < _tables.size(); i++)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				Node* next = cur->_next;
				delete cur;

				cur = next;
			}

			_tables[i] = nullptr;
		}
	}

	bool Insert(const T& data)
	{
		KeyOfT kot;

		if (Find(kot(data)))
			return false;

		Hash hash;

		// 负载因子 == 1时扩容
		if (_n == _tables.size())
		{
			/*HashTable<K, V> newht;
			newht._tables.resize(__stl_next_prime(_tables.size() + 1));
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					newht.Insert(cur->_kv);
					cur = cur->_next;
				}
			}

			_tables.swap(newht._tables);*/
			vector<Node*> newTable(__stl_next_prime(_tables.size() + 1));
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					// 头插到新表
					size_t hashi = hash(kot(cur->_data)) % newTable.size();
					cur->_next = newTable[hashi];
					newTable[hashi] = cur;

					cur = next;
				}

				_tables[i] = nullptr;

			}

			_tables.swap(newTable);
		}

		size_t hashi = hash(kot(data)) % _tables.size();
		// 头插
		Node* newnode = new Node(data);
		newnode->_next = _tables[hashi];
		_tables[hashi] = newnode;
		++_n;

		return true;
	}

	Node* Find(const K& key)
	{
		KeyOfT kot;

		Hash hash;
		size_t hashi = hash(key) % _tables.size();
		Node* cur = _tables[hashi];
		while (cur)
		{
			if (kot(cur->_data) == key)
			{
				return cur;
			}

			cur = cur->_next;
		}

		return nullptr;
	}

	bool Erase(const K& key)
	{
		size_t hashi = key % _tables.size();
		Node* prev = nullptr;
		Node* cur = _tables[hashi];
		while (cur)
		{
			if (kot(cur->_data) == key)
			{
				if (prev == nullptr)
				{
					// 头结点
					_tables[hashi] = cur->_next;
				}
				else
				{
					// 中间节点
					prev->_next = cur->_next;
				}

				delete cur;
				--_n;

				return true;
			}
			else
			{
				prev = cur;
				cur = cur->_next;
			}
		}

		return false;
	}
private:
	vector<Node*> _tables; // 指针数组
	size_t _n = 0;		   // 表中存储数据个数
};