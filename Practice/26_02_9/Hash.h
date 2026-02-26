#pragma once
#include<iostream>
using namespace std;
#include<vector>

enum State
{
	EXIST,
	EMPTY,
	DELETE
};

template<class K, class V>
struct HashDate
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

template<class K, class V>
class HashTable
{
public:
	HashTable()
		:_tables(11)
		,_n(0)
	{ }

	bool Insert(const pair<K, V>& kv)
	{
		// 不允许冗余
		if (Find(kv.first))
			return false;

		// 负载因子 >= 0.7 扩容
		if (_n * 1.0 / _tables.size() >= 0.7)
		{
			// 创建个哈希表
			HashTable<K, V> NewHash;
			// 用reserve扩容到两倍
			NewHash._tables.reserve(_tables.size() * 2);
			for (auto& data : _tables) // 插入旧表中存在的值
			{
				if (data._state == EXIST)
				{
					NewHash.Insert(data._kv);
				}
			}
			// 新旧表交换数据
			_tables.swap(NewHash._tables);
		}

		// 找需插入的位置
		size_t Hash0 = kv.first % _tables.size();
		size_t Hashi = Hash0; // 记录插入位置
		int i = 1; // 线性探测需++

		// 找空位置
		while (_tables[Hashi]._state == EXIST)
		{
			Hashi = (Hash0 + i) % _tables.size();
			++i;
		}

		// 找到了插入到空位置
		_tables[Hashi]._kv = kv;
		_tables[Hashi]._state = EXIST;
		++_n;

		return true;
	}

	HashDate<K, V>* Find(const K& key)
	{
		size_t hash0 = key % _tables.size();
		size_t hashi = hash0;
		int i = 1;
		while (_tables[hashi]._state != EMPTY)
		{
			if (_tables[hashi]._kv.first == key)
			{
				return &_tables[hashi];
			}

			hashi = (hash0 + i) % _tables.size();
		}

		return nullptr;
	}

	bool Erase(const K& key)
	{
		HashDate<K, V>* ret = Find(key);
		if (ret)
		{
			ret->_state = DELETE; // 删除直接改状态即可 
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	vector<HashDate<K, V>> _tables;
	size_t _n; // 记录数据个数
};