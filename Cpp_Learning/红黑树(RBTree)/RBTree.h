#pragma once
#include <iostream> 
#include <utility>
using namespace std;

// 枚举值表示颜色
enum Colour
{
	RED,
	BLACK
};

// 红黑树节点结构
template<class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;              // 键值对
	RBTreeNode<K, V>* _left;     // 左孩子
	RBTreeNode<K, V>* _right;    // 右孩子
	RBTreeNode<K, V>* _parent;   // 父节点（红黑树必须维护父节点）
	Colour _col;                 // 节点颜色

	// 构造函数
	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED) {
	} // 默认红（插入时默认红，减少黑高破坏）
	{}
};

// 红黑树类
template<class K, class V>
class RBTree
{
	using Node = RBTreeNode<K, V>;
public:
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

        // 4. 重置平衡因子
        parent->_bf = subR->_bf = 0;
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

        // 4. 重置平衡因子（旋转后子树高度恢复，BF归0）
        parent->_bf = subL->_bf = 0;
    }

	// 插入接口
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

			if (parent == grandfater->_left) // 叔叔在右边
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

		return true;
	}

	// 中序遍历（验证二叉搜索树特性）
	void InOrder() { _InOrder(_root); cout << endl; }

	// 查找接口
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

	// 获取树的大小
	int Size() { return _Size(_root); }

	// 获取树的高度
	int Height() { return _Height(_root); }

private:
	// 私有递归函数
	/*public*/
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	/*private*/
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

private:
	Node* _root = nullptr;
};