#define _CRT_SECURE_NO_WARNINGS
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
	template<class K, class V>
	bool insert(const K& key, const V& value)
	{
		// 情况1：树为空
		if (_root == nullptr)
		{
			_root = new Node<K, V>;
			return tree;
		}

		// 情况2：树不为空
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) // 找到空节点
		{
			if (cur->_kv < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv > key)
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
		cur = new Node(key, value);
		if (parent->_kv < key)
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

			}
			else
			{
				assert(false);
			}
		}
		return true;
	}


private:
	Node* _root = nullptr;
};

int main()
{


	return 0;
}