#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 结构
template<class K>
struct BSTNode
{
	K _key; // 接收值
	BSTNode<K>* _left;	// 左孩子节点
	BSTNode<K>* _right; // 右孩子节点
	BSTNode(const K& key) // 默认构造
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{
	}
};

template<class K>
class BSTree
{
	//typedef BSTNode<K> Node;	// 普通写法
	using Node = BSTNode<K>;	// C++11写法
public:
	bool Insert(const K& key)
	{
		// 情况一：树为空
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		// 情况二：树不为空
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) // 遍历树(找到空就放入)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false; // 若相等，不插入
			}
		}

		cur = new Node(key); // 创建节点，未连接
		if (parent->_key < key) // 大的连接右边
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	// 查找
	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
	}

	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) // 循环遍历找key相等的节点
		{
			if (cur->_key < key) // 右遍历
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key) // 左遍历
			{
				parent = cur;
				cur = cur->_left;
			}
			else // 找到要删除的节点了
			{
				if (cur->_left == nullptr) // 只有叶子节点或一个孩子(左为空)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}

					delete cur;
				}
				else if (cur->_right == nullptr) // 只有叶子节点或一个孩子(右为空)
				{
					if (_root == cur)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_right == cur)
						{
							parent->_right = cur->_left;
						}
						else
						{
							parent->_left = cur->_left;
						}
					}

					delete cur;
				}
				else // 左右都不为空
				{
					// 最小节点 = 右子树最左节点
					Node* replaceParent = cur;	 // replace的父节点要连接
					Node* replace = cur->_right; // 右子树
					while (replace->_left)	// 往左遍历找最小
					{
						replaceParent = replace;
						replace = replace->_left;
					}
					cur->_key = replace->_key;

					if (replaceParent->_left == replace)
						replaceParent->_left = replace->_right; // 因为replace的左为空，需父节点连接右节点
					else
						replaceParent->_right = replace->_right;	 // 因为replace的左为空，需父节点连接右节点

					delete replace;
				}
				return true;
			}
		}
		return false;
	}

	void InOrder() // 在类中调用中序，可以给外面拿到_root
	{
		_InOrder(_root); // 类中二叉树递归都用这个方式访问_root
		cout << endl;
	}

private:
	// 因为_root是私有，外面拿不了
	void _InOrder(Node* root) // 中序遍历
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	Node* _root = nullptr; // 根节点的指针
};

// 测试key版本的二叉搜索树
void TestBSTree()
{
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	cout << "中序遍历（升序）：";
	t.InOrder(); // 输出：1 3 4 6 7 8 10 13 14

	cout << "查找6：" << (t.Find(6) ? "成功" : "失败") << endl; // 成功
	cout << "删除3：" << (t.Erase(3) ? "成功" : "失败") << endl; // 成功
	cout << "删除后中序遍历：";
	t.InOrder(); // 输出：1 4 6 7 8 10 13 14
}

int main()
{
	TestBSTree();
	return 0;
}