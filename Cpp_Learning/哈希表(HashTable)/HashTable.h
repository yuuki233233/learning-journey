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

template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

// 仿函数（绝对值）
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 仿函数（字符串比较）
template<>
struct HashFunc<string> // 模板特化
{
	// 字符串转换成整形，可以把字符ASCII码值相加
	// 但是直接相加的话，"abcd"和"bcad"计算出的ASCII码值相同
	// 这里我们使用BKDR哈希的思路，用上次的计算结果取乘一个质数，这个质数一般是31，131
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash *= 131; 
			hash += ch;
		}

		return hash;
	}
};

// 统计相差大概2倍的素数(用于数组扩容)
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

namespace HashTable
{
	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
			:_tables(__stl_next_prime(0))
			, _n(0)
		{
		}

		bool Insert(const pair<K, V>& kv)
		{
			// 禁止数据冗余
			if (Find(kv.first))
				return false;

				// 负载因子 >= 0.7扩容
			if (_n * 10 / _tables.size() >= 7)
			{
				HashTable<K, V, Hash> newht;
				newht._tables.resize(__stl_next_prime(_tables.size() + 1));
				for (auto& data : _tables)
				{
					// 旧表的数据映射到新表
					if (data._state == EXIST)
					{
						newht.Insert(data._kv);
					}
				}

				_tables.swap(newht._tables);
			}

			Hash hash;
			size_t hash0 = hash(kv.first) % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;
			int flag = 1;
			while (_tables[hashi]._state == EXIST)
			{
				// 线性探测
				hashi = (hash0 + i) % _tables.size();
				++i;

				// 二次探测
				/*hashi = (hash0 + (i*i*flag)) % _tables.size();
					if (hashi < _tables.size())
						hashi += _tables.size();

					if (flag == 1)
					{
						flag = -1;
					}
					else
					{
						++i;
						flag = 1;
					}*/
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hash;
			size_t hash0 = key % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				// 线性探测
				hashi = (hash0 + i) % _tables.size();
				++i;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				return true;
			}
			else
			{
				return false;
			}
		}
	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0; // 记录插入节点数量
	};
}

namespace HashBucket
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{ }
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		HashTable()
			:_tables(11)
			,_n(0)
		{ }

		bool Insert(const pair<K, V>& kv)
		{
			// 负载因子 == 1时扩容
			if (_n == _tables.size())
			{
				vector<Node*> newTable(_tables.size() * 2);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						// 新表的位置
						size_t hashi = kv.first % newTable.size();
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTable);
			}

			size_t hashi = kv.first % _tables.size();
			// 头插
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return true;
		}

		Node* Find(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
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
				if (cur->_kv.first == key)
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
		size_t _n = 0;		   // 表中数据个数
	};
}