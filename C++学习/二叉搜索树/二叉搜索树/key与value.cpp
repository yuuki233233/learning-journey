#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

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



// 测试键值对版本的二叉搜索树
void TestBSTreeKV()
{
	BSTreeKV<string, int> dict;
	dict.Insert("apple", 1);
	dict.Insert("banana", 2);
	dict.Insert("orange", 3);

	cout << "中序遍历键值对：";
	dict.InOrder(); // 输出：key: apple, value: 1 key: banana, value: 2 key: orange, value: 3

	// 修改banana的value
	int* p = dict.Find("banana");
	if (p)
	{
		*p = 20;
	}
	cout << "修改后中序遍历：";
	dict.InOrder(); // 输出：key: apple, value: 1 key: banana, value: 20 key: orange, value: 3
}

int main()
{
	TestBSTreeKV();
	return 0;
}