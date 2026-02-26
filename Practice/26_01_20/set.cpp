#include<map>
#include<iostream>
using namespace std;


int main()
{
	// 内层的{"left", "左边"}隐式类型转换 -> pair，外层的dict = {}隐式类型转换 -> map
	map<string, string> dict = { {"left", "左边"}, {"right", "右边"}, {"insert", "插入"}, {"cout", "输出"} };

	// 方式1：有名对象
	//map<string, string> dict;
	pair<string, string> kv1("first", "第一个");
	dict.insert(kv1);

	// 方式2：匿名对象
	dict.insert(pair<string, string>("second", "第二个"));

	// 方式3：调用make_pair(函数模板，编译器自动推理模板类型并返回)
	dict.insert(make_pair("sort", "排序"));

	// 方式4：隐式类型转换
	dict.insert({ "auto", "自动" });

	// 插入是只看key，value不相等不会更新
	dict.insert({ "auto", "zidong" });

	// 遍历map
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// 可以修改value，不支持修改key
		//it->first += 'x';
		it->second += 'x';

		// C++不支持返回多个值
		//cout << *it << endl;

		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		// it->first访问是省略后的，下面是原始的访问
		//cout << it.operator->()->first << ":" << it.operator->()->second << endl;
		++it;
	}
	
	
	return 0;
}