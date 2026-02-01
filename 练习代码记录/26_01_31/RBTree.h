#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

// 枚举值表示颜色
enum Colour
{
	RED,
	BLACK
};

// 默认key/value结构实现
template<class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{ }
};

template<class K, class V>
class RBTree
{
	using Node = RBTreeNode<K, V>;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;

			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = RED;	// 新节点为红色
		if (parent->_kv.first < kv.first)
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
						parent->_col = BLACK;
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

		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if(subLR)
			subLR->_parent = parent;

		Node* pParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
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

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parentParent == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

	int Size()
	{
		return _Size(_root);
	}

	int Height()
	{
		return _Height(_root);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight(root->_left);
		int rightHeight(root->_right);
		return rightHeight > leftHeight ? leftHeight + 1 : rightHeight + 1;
	}

	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	Node* _root = nullptr;
};