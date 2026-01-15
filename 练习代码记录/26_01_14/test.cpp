#define _CRT_SECURE_NO_WARNINGS
#include"Binary_Search_Tree.h"

//int main()
//{
//	BSTree<int> b;
//	int a[] = { 8, 3, 1, 10, 1, 6, 4, 7, 14, 13 };
//	for (auto e : a)
//	{
//		b.Insert(e);
//	}
//	b.InOrder();
//
//	b.Insert(16);
//	b.InOrder();
//
//	b.Erase(3);
//	b.InOrder();
//
//	b.Erase(8);
//	b.InOrder();
//
//	for (auto e : a)
//	{
//		b.Erase(e);
//		b.InOrder();
//	}
//
//	return 0;
//}

// 测试key版本的二叉搜索树
void TestBSTree()
{
	BS::BSTree<int> t;
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

// 测试键值对版本的二叉搜索树
void TestBSTreeKV()
{
	KV::BSTreeKV<string, int> dict;
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
	TestBSTree();
	TestBSTreeKV();
	return 0;
}