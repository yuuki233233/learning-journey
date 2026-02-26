#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include<map>
//int main()
//{
//	// 初始化方式：使用花括号包裹每个 pair
//	map<string, string> m{ {"hello", "world"}, {"left", "左边"}, {"right", "右边"} };
//
//	// 当key中没有时则插入
//	m["sort"];
//
//	// 有无key情况：
//	// 
//	// 情况1：[]找到key(left)，然后修改T
//	m["left"] = "左边剩余";
//
//	// 情况2：无insert，插入加修改
//	m["insert"] = "插入";
//
//	// []也可以实现查找，但要注意以上两种情况，确保有key时查找，不然就插入新数据
//	cout << m["left"] << endl;
//	cout << m["operator"] << endl << endl;;
//
//	for (const auto& e : m)
//	{
//		cout << e.first << " " << e.second << endl;
//	}
//	return 0;
//}

//int main()
//{
//	map<string, string> m = { {"1", "sort"}, {"2", "insert"}, {"3", "qsort"}, {"4", "memcopy"}};
//	for (const auto& e : m)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//
//	string str;
//	while (cin >> str)
//	{
//		if (m.find(str) != m.end())
//		{
//			cout << "找到了！！" << endl;
//		}
//		else
//		{
//			cout << "没找到" << endl;
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	string arr[]{ "苹果","香蕉", "葡萄", "苹果", "苹果", "草莓", "香蕉", "苹果", "草莓" };
//	map<string, int> m;
//	for (auto e : arr)
//	{
//		auto ret = m.find(e);
//		if (ret == m.end())
//		{
//			m.insert({e, 1});
//		}
//		else
//		{
//			ret->second++;
//		}
//	}
//
//	for (auto e : m)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//
//	return 0;
//}

int main()
{
	multimap<string, string> m{ {"X", "星链"}, {"X", "特斯拉"}, {"X", "火箭"} };

	// 查找
	auto ret = m.find("X"); // 中序第一个
	cout << ret->first << ":" << ret->second << endl;

	// 插入
	m.insert({ "Apple", "手机" });
	m.insert({ "Apple", "笔记本" });

	// 删除(key为X)
	m.erase("X");

	return 0;
}