#pragma once
#include<iostream>
using namespace std;

namespace BS
{
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
}

namespace KV
{
	// 键值对版本的节点结构
	template<class K, class T>
	struct BSTNodeKV
	{
		K _key;
		T _value;
		BSTNodeKV<K, T>* _left;
		BSTNodeKV<K, T>* _right;

		BSTNodeKV(const K& key, const T& value)
			:_key(key)
			, _value(value)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
	};

	// 键值对版本的二叉搜索树
	template<class K, class T>
	class BSTreeKV
	{
		using Node = BSTNodeKV<K, T>;
	public:
		// 插入键值对
		bool Insert(const K& key, const T& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
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
					return false; // 不支持重复key
				}
			}

			cur = new Node(key, value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}

		// 查找key并返回value的指针（方便修改value）
		T* Find(const K& key)
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
					return &(cur->_value); // 返回value地址，支持修改
				}
			}
			return nullptr; // 查找失败
		}

		// 删除（逻辑与key版本一致，略）
		bool Erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
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
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
								parent->_left = cur->_right;
							else
								parent->_right = cur->_right;
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_right == cur)
								parent->_right = cur->_left;
							else
								parent->_left = cur->_left;
						}
						delete cur;
					}
					else
					{
						Node* replaceParent = cur;
						Node* replace = cur->_right;
						while (replace->_left)
						{
							replaceParent = replace;
							replace = replace->_left;
						}
						// 替换key和value
						cur->_key = replace->_key;
						cur->_value = replace->_value;

						if (replaceParent->_left == replace)
							replaceParent->_left = replace->_right;
						else
							replaceParent->_right = replace->_right;

						delete replace;
					}
					return true;
				}
			}
			return false;
		}

		// 中序遍历（打印key和value）
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << "key: " << root->_key << ", value: " << root->_value << " ";
			_InOrder(root->_right);
		}

		Node* _root = nullptr;
	};
}

