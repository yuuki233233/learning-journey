#pragma once
#include"HashTable.h"

namespace yuuki
{
	template<class K, class Hash = HashFunc<K>>
	class unorder_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename HashTable<K, K, SetKeyOfT>::Iterator iterator;
		typedef typename HashTable<K, const K, SetKeyOfT>::ConstIterator const_iterator;


		bool insert(const K& key)
		{
			return _t.Insert(key);
		}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}



	private:
		HashTable<K, K, SetKeyOfT> _t;
	};
}