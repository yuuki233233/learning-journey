#pragma once

#include"RBTree.h"

namespace yuuki
{
	/*
	* 在 stl_map 中，第二个模板参数用的是 T，改为 V（Value）会更好
	 */
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		/*
		* 这里属于：内部类取内嵌类型，因为这里的内模板没有实例化 set，编译器区别不了
		* 无论 isert 还是 iterator 本质都是调用下层
		*/
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::ConstIterator const_iterator;


		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		const_iterator begin() const
		{
			return _t.Begin();
		}

		const_iterator end() const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		// C++中，[]充当了插入，查找，修改的功能，需要包 insert
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert({ key, V() });
			return ret.first->second;
		}

	private:
		// 对于 set 而言，第二个模板参数传的是 key
		// 对于 map 而言，第二个模板参数传的是 pair 
		/*
		* 这里跟 set 一样，把 pair 中第一个模板参数改成 const K，也要记得将上面红黑树的模板参数也一同更改
		*  只需要将 Mymap.h 中的 typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::Iterator iterator; 改成 ->
		*					   typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Iterator iterator;
		*/
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}