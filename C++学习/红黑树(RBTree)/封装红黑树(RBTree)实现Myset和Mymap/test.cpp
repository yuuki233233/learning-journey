#define _CRT_SECURE_NO_WARNINGS
#include"RBTree.h"
#include"Myset.h"
#include"Mymap.h"

// 实现反向迭代器
void set_re_print(const yuuki::set<int>& s)
{
	yuuki::set<int>::const_iterator it = s.end();
	while(it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	yuuki::set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(6);

	yuuki::set<int>::iterator sit = s.begin();
	/*
	* set 不能修改，详见 Myset.h 中 private 中的解析
	*/
	//*sit += 10;
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set_re_print(s);

	yuuki::map<string, string> dict;
	dict.insert({ "sort", "排序" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边" });

	dict["left"] = "左边，剩余";
	dict["insert"] = "插入";
	dict["string"];


	yuuki::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& e : dict)
	{
		/*
		* map 中的 frist 不能修改，详见 Mymap.h 中 private 中的解析
		*/
		//e.first += 'x';
		e.second += 'y';
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	return 0;
}