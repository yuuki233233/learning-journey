#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{ }
};

template<class K, class V>
class AVLTree
{
	using Node = AVLTreeNode<K, V>;

public:
	bool insert(const pair<K, V>& kv)
	{
		// 情况1：树为空
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		// 情况2：树不为空
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) // 找到空节点
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		// 插入空节点
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		// 更新平衡因子
		while (parent)
		{
			// 更新平衡因子
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0)
			{
				// 平衡退出
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if(parent->_bf == 2 || parent->_bf == -2)
			{
				// 不平衡，旋转处理
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{

				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	// 右旋
	void RotateR(Node* parent)
	{
		// 最核心部分
		/*Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		parent->_left = SubLR;
		SubL->_right = parent;*/

		
		// 核心三节点，不需要其他节点
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;


		parent->_left = SubLR;		// 1.需画图理解

		// 对应h = 0
		if(SubLR != nullptr)
			SubLR->_parent = parent;	// 2.要满足父节点(左指针或右指针) -> 子节点，子节点(父指针) -> 父节点

		SubL->_right = parent;		// 满足 1.
		parent->_parent = SubL;		// 满足 2.

	
		Node* pParent = parent->_parent;
		if (parent == _root)	/*根为根节点*/
		{
			_root = SubL;
			SubL->_parent = nullptr;
		}
		else	/*根为子树*/
		{
			if (pParent->_left == parent)
			{
				pParent->_left = SubL;
			}
			else
			{
				pParent->_right = SubL;
			}
		}
		
		// 旋转完，更新平衡因子
		SubL->_bf = parent->_bf = 0;
	}

	// 左旋
	void RotateL(Node* parent)
	{
		// 核心三节点，不需要其他节点
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		parent->_right = SubRL;
		SubR->_left = parent;
		parent->_parent = SubR;
		if(SubRL != nullptr)
			SubRL->_parent = parent;

		Node* pParent = parent->_parent;
		if (parent == _root)
		{
			_root = SubR;
			SubR->_parent = nullptr;
		}
		else
		{
			if (pParent->_left == parent)
			{
				pParent->_left = SubR;
			}
			else
			{
				pParent->_right = SubR;
			}
		}

		parent->_bf = SubR->_bf = 0;
	}

	// 左右双旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 0)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	// 右左双旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		if (bf == 0)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if(bf == -1)
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == 1)
		{
			subR->_bf = 1;
			subRL->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
private:
	Node* _root = nullptr;
};

