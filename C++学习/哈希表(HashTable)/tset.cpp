#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include"HashTable.h"

int main()
{
	//int a[] = { 19,30,52,63,11,22 };
	int a[] = { 19,30,5,36,13,20,21,12 };
	HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert({ e, e });
	}

	//ht.Insert({ 15, 15 });

	ht.Erase(30);
	if (ht.Find(20))
	{
		cout << "找到了" << endl;
	}

	if (ht.Find(30))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

	return 0;
}

struct StringHashFunc
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
		}

		return hash;
	}
};

struct Date
{
	int _year;
	int _month;
	int _day;

	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
};

struct DateHashFunc
{
	size_t operator()(const Date& d)
	{
		size_t hash = 0;
		hash += d._year;
		hash *= 131;

		hash += d._month;
		hash *= 131;

		hash += d._day;
		hash *= 131;

		return hash;
	}
};

int main()
{
	//int a[] = { 19,30,52,63,11,22 };

	const char* a1[] = { "abcd", "sort", "insert" };
	HashTable<string, string> ht1;
	for (auto& e : a1)
	{
		ht1.Insert({ e, e });
	}

	cout << HashFunc<string>()("abcd") << endl;
	cout << HashFunc<string>()("bcad") << endl;
	cout << HashFunc<string>()("aadd") << endl;

	int a2[] = { -19,-30,5,36,13,20,21,12 };
	HashTable<int, int> ht2;
	for (auto e : a2)
	{
		ht2.Insert({ e, e });
	}

	// 哈希冲突
	HashTable<Date, int, DateHashFunc> ht;
	ht.Insert({ { 2024, 10, 12 }, 1 });
	ht.Insert({ { 2024, 12, 10 }, 1 });

	return 0;
}