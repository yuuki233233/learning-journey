#pragma once

#include"RBTree.h"

namespace yuuki
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		/*
		* 这里属于：内部类取内嵌类型，因为这里的内模板没有实例化 set，编译器区别不了
		* 无论 isert 还是 iterator 本质都是调用下层
		*/
		typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, const K, SetKeyOfT>::ConstIterator const_iterator;


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

		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}

	private:
		// 对于 set 而言，第二个模板参数传的是 key
		// 对于 map 而言，第二个模板参数传的是 pair
		/*
		* 因为 set 不能修改，这里可以将 value 的值改为const，但是会出现巨大的坑
		* 修改后会显示 _t.End()报错，但这部分没有错误
		* 
		* 原因：因为这里改成 const int,传给红黑树第二个模板参数就是 const int 类型
		* 最终红黑树里 _node->data 节点为 const int 类型，解引用放返回也不能修改，所以 _t.End()报错
		* 只需要将 Myset.h 中的 typedef typename RBTree<K, K, SetKeyOfT>::Iterator iterator 改成 ->
		*					   typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator
		*/
		RBTree<K, const K, SetKeyOfT> _t;
	};
}