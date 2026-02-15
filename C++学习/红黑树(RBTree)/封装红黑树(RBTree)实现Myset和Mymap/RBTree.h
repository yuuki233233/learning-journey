#pragma once
#include <iostream> 
#include <utility>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

/*
* 这里的 RBTree 里的模板参数要跟 _stl_tree 保持一致
* 原本为固定的数据类型 pair<K, V> 改成 泛型 T _data;
 */
template<class T>
struct RBTreeNode
{
	T _data;              // 键值对
	RBTreeNode<T>* _left;     // 左孩子
	RBTreeNode<T>* _right;    // 右孩子
	RBTreeNode<T>* _parent;   // 父节点（红黑树必须维护父节点）
	Colour _col;                 // 节点颜色

	// 构造函数
	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)// 默认红（插入时默认红，减少黑高破坏）
	{}
};

/*
* 考虑到有 iterator 和 const_iterator 两种迭代器
* 需要传 Ref 和 Ptr 模板参数
 */
template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;

	Node* _node;
	Node* _root; // 这里传根节点为了支持实现 end--，注意下面迭代器也要跟着改动

	RBTreeIterator(Node* node, Node* root)
		:_node(node)
		,_root(root)
	{ }

	Self& operator++()
	{
		if (_node->_right)
		{
			// 右不为空，访问 cur 右子树的最左节点
			Node* min = _node->_right;
			while (min->_left)
			{
				min = min->_left;
			}

			_node = min;
		}
		else
		{
			// 右为空，访问父亲节点（1.cur 在父亲的左边 2.cur 在父亲的右边）
			Node* cur = _node;
			Node* parent = cur->_parent;
			// cur 可能走到根节点，父节点为NULL
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{
		if (_node == nullptr) // --end()
		{
			// --end(),特殊处理，走到中序最后一个节点，整棵树的最右节点
			Node* max = _root;
			while (max && max->_right)
			{
				max = max->_right;
			}

			_node = max;
		}
		else if (_node->_left)
		{
			// 左子树不为空，中序左子树最后一个
			Node* max = _node->_left;
			while (max->_right)
			{
				max = max->_right;
			}

			_node = max;
		}
		else
		{
			// 右为空，访问父亲节点（1.cur 在父亲的左边 2.cur 在父亲的右边）
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator==(const Self& s) const
	{
		return s._node == _node;
	}

	bool operator!=(const Self& s) const
	{
		return s._node != _node;
	}
};

/*
* 在原模板的基础上，新添加个模板类似，该模板类型是仿函数
 */
template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	// 迭代器
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

	Iterator Begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return Iterator(cur, _root);
	}

	// 这里用 End = NULL 有好处
	// 1. 如果 _root = NULL，cur = NULL，End = Begin
	Iterator End()
	{
		return Iterator(nullptr, _root);
	}

	ConstIterator Begin() const
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return ConstIterator(cur, _root);
	}

	ConstIterator End() const
	{
		return ConstIterator(nullptr, _root);
	}

	/*
	* 1. 不支持[]，只返回 bool 即可
	* 
	* 2. 若支持[]，需返回 pair<Iterator, bool>
	*     - 当插入成功，返回 pair<Iterator, true>
	*     - 当插入失败，返回 pair<Iterator, false>
	*/
	pair<Iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;

			// return ture
			// return pair<Iterator, bool>(Iterator(_root, _root), true);
			return { Iterator(_root, _root), true };
		}

		/*
		* set 直接用 data(key) 比较是没有问题的，但是 map 不能用 pair 进行比较
		* map 的比较要用到 data.first(pair<K, V>._kv.first)，但 set 又不支持用 first
		*
		* 如何解决：需另外用到仿函数(KeyOfT)
		 */
		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return { Iterator(cur, _root), false };

			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;	// 新节点为红色
		if (kot(parent->_data) < kot(data))
			parent->_right = cur;
		else
			parent->_left = cur;
		// 链接父亲
		cur->_parent = parent;

		// 父亲是红色，出现连续的红色节点（需处理）
		while (parent && parent->_col == RED) // 分两种情况：1.叔叔在左边 2.叔叔在右边
		{	// 条件parent：防止空指针（_root节点的父亲为NULL）
			Node* grandfater = parent->_parent;

			if (parent = grandfater->_left) // 叔叔在右边
			{
				//   g
				// p   u
				Node* uncle = grandfater->_right;
				if (uncle && uncle->_col == RED)	// 叔叔存在且为红色（变色）
				{
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;

					// 继续向上处理，最坏结果处理到根
					cur = grandfater;
					parent = cur->_parent;
				}
				else // 叔叔不存在，或存在且为黑（旋转+变色）
				{
					if (cur == parent->_left) // c在父亲左边，构成直线，只单旋一次
					{
						//     g
						//   p   u
						// c
						RotateR(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else// c在父亲右边，构成折现，需要双旋
					{
						//     g
						//   p   u
						//    c
						RotateL(parent);
						RotateR(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}

					break;
				}
			}
			else // 叔叔在左边（类似上列代码）
			{
				//   g
				// u   p
				Node* uncle = grandfater->_left;

				// 叔叔存在且为红（变色即可）
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;

					// 继续向上处理
					cur = grandfater;
					parent = cur->_parent;
				}
				else// 叔叔不存在，或存在且为黑（旋转+变色）
				{
					//     g
					//   u   p
					//         c
					if (cur == parent->_right)
					{
						RotateL(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else
					{
						//     g
						//   u   p
						//      c
						RotateR(parent);
						RotateL(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}

					break;
				}
			}
		}
		_root->_col = BLACK; // _root节点必为BLACK

		/*
		* 这里由 { Iterator(cur, _root), true } 变成 
		* { Iterator(newnode, _root), true }; 
		* 这是为了避免因为 [] 而连续变色
		*/
		return { Iterator(newnode, _root), true };

	}

	// 查找接口
	Iterator Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->kot(cur->_data) < kot(key))
			{
				cur = cur->_right;
			}
			else if (cur->kot(cur->_data) > kot(key))
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return End();
	}

	// 获取树的大小
	int Size() { return _Size(_root); }

	// 获取树的高度
	int Height() { return _Height(_root); }

private:
	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight(root->_left);
		int rightHeight(root->_right);
		return rightHeight > leftHeight ? leftHeight + 1 : rightHeight + 1;
	}

	// 左旋转：以parent为旋转点，右孩子上位
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;    // 失衡节点的右孩子（新根）
		Node* subRL = subR->_left;      // 新根的左子树（需要转移）
		Node* pParent = parent->_parent; // 失衡节点的父节点

		// 1. 转移subRL：挂到parent的右子树
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		// 2. 父节点降级：parent作为subR的左孩子
		subR->_left = parent;
		parent->_parent = subR;

		// 3. 链接新根到原父节点
		if (pParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (pParent->_left == parent)
				pParent->_left = subR;
			else
				pParent->_right = subR;
			subR->_parent = pParent;
		}
	}

	// 右旋转：以parent为旋转点，左孩子上位
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;    // 失衡节点的左孩子（新根）
		Node* subLR = subL->_right;    // 新根的右子树（需要转移）
		Node* pParent = parent->_parent; // 失衡节点的父节点

		// 1. 转移subLR：挂到parent的左子树
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		// 2. 父节点降级：parent作为subL的右孩子
		subL->_right = parent;
		parent->_parent = subL;

		// 3. 链接新根到原父节点
		if (pParent == nullptr)
		{
			// 原parent是根节点，更新根
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (pParent->_left == parent)
				pParent->_left = subL;
			else
				pParent->_right = subL;
			subL->_parent = pParent;
		}
	}

	void Destory(Node* root)
	{
		if (root == nullptr)
			return;

		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newRoot = new Node(root->_kv);
		newRoot->_left = Copy(root->_left);
		newRoot->_right = Copy(root->_right);

		return newRoot;
	}

private:
	Node* _root = nullptr;
};