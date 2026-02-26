#pragma once
#include<iostream>
using namespace std;

// AVLTree节点结构
template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;              // 键值对（实用化改造）
	AVLTreeNode<K, V>* _left;    // 左孩子
	AVLTreeNode<K, V>* _right;   // 右孩子
	AVLTreeNode<K, V>* _parent;  // 父节点（旋转时需回溯）
	int _bf;                     // 平衡因子（初始为0）

	// 构造函数简化（直接初始化键值对）
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{
	}
};

template<class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;
public:
    bool Insert(const K& key, const V& value)
    {
        // 1. 空树直接插入根节点
        if (_root == nullptr)
        {
            _root = new Node(make_pair(key, value));
            return true;
        }

        // 2. 非空树：按BST规则找插入位置
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur)
        {
            if (cur->_kv.first < key) // 键值对比（修正原_kv直接比较的错误）
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                // 键已存在，插入失败（符合set/map的特性）
                return false;
            }
        }

        // 3. 创建新节点并链接到父节点
        cur = new Node(make_pair(key, value));
        if (parent->_kv.first < key)
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }
        cur->_parent = parent; // 维护父节点指针

        // 4. 回溯更新平衡因子 + 平衡检查
        while (parent)
        {
            // 4.1 更新当前父节点的平衡因子
            if (cur == parent->_left)
                parent->_bf--; // 左子树新增节点，BF-1
            else
                parent->_bf++; // 右子树新增节点，BF+1

            // 4.2 平衡因子状态判断
            if (parent->_bf == 0)
            {
                // 平衡因子归0：子树高度未变，无需继续回溯
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1)
            {
                // 平衡因子从0→±1：子树高度增加，继续向上更新
                cur = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2)
            {
                // 失衡：根据失衡类型旋转
                if (parent->_bf == 2)
                {
                    // 右子树过高：分两种情况
                    if (cur->_bf == 1)
                    {
                        // 右单旋（直线型失衡）
                        RotateL(parent);
                    }
                    else // cur->_bf == -1
                    {
                        // 右左双旋（折线型失衡）
                        RotateRL(parent);
                    }
                }
                else // parent->_bf == -2
                {
                    // 左子树过高：分两种情况
                    if (cur->_bf == -1)
                    {
                        // 右单旋（直线型失衡）
                        RotateR(parent);
                    }
                    else // cur->_bf == 1
                    {
                        // 左右双旋（折线型失衡）
                        RotateLR(parent);
                    }
                }
                // 旋转后平衡恢复，停止回溯
                break;
            }
            else
            {
                // 平衡因子异常（如±3），说明代码逻辑错误
                assert(false && "平衡因子超出合法范围");
            }
        }

        return true;
    }

    // 查找指定键对应的节点（返回值为Node*，方便扩展）
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
                // 找到节点，返回指针
                return cur;
            }
        }
        // 未找到，返回空
        return nullptr;
    }

private:
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

    // 左右双旋
    void RotateLR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf; // 记录旋转中心的BF，用于后续重置

        // 第一步：对subL做左单旋
        RotateL(subL);
        // 第二步：对parent做右单旋
        RotateR(parent);

        // 根据旋转中心的BF，重置所有节点的平衡因子
        if (bf == 0)
        {
            // 旋转中心是新增节点，所有BF归0
            parent->_bf = subL->_bf = subLR->_bf = 0;
        }
        else if (bf == -1)
        {
            // 新增节点在subLR的左子树
            parent->_bf = 1;
            subL->_bf = 0;
            subLR->_bf = 0;
        }
        else if (bf == 1)
        {
            // 新增节点在subLR的右子树
            parent->_bf = 0;
            subL->_bf = -1;
            subLR->_bf = 0;
        }
        else
        {
            assert(false && "旋转中心平衡因子异常");
        }
    }

    // 右左双旋
    void RotateRL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf; // 记录旋转中心的BF

        // 第一步：对subR做右单旋
        RotateR(subR);
        // 第二步：对parent做左单旋
        RotateL(parent);

        // 重置平衡因子
        if (bf == 0)
        {
            parent->_bf = subR->_bf = subRL->_bf = 0;
        }
        else if (bf == 1)
        {
            // 新增节点在subRL的右子树
            parent->_bf = -1;
            subR->_bf = 0;
            subRL->_bf = 0;
        }
        else if (bf == -1)
        {
            // 新增节点在subRL的左子树
            parent->_bf = 0;
            subR->_bf = 1;
            subRL->_bf = 0;
        }
        else
        {
            assert(false && "旋转中心平衡因子异常");
        }
    }
private:
    Node* _root = nullptr; // 根节点初始化
};