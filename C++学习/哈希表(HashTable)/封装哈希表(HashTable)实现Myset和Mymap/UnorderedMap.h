#pragma once
#include"HashTable.h"

namespace yuuki
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unorder_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}

	private:
		HashTable<K, pair<K, V>, MapKeyOfT> _t;
	};
}