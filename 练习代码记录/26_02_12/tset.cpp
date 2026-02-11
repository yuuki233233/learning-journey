#define _CRT_SECURE_NO_WARNINGS
#include"HashTable.h"

void test_HashTable()
{
	int a[] = { 2,5,8,4,9,10 };
	HashTable::HashTable<int, int> _ht;
	for (auto e : a)
	{
		_ht.Insert({ e, e });
	}

	cout << _ht.Find(2) << endl;
	cout << _ht.Find(10) << endl;
	cout << _ht.Find(3) << endl;
}

void test_HashBucket()
{
	int a2[] = { 19,30,5,36,13,20,21,12,24,96 };
	HashBucket::HashTable<int, int> ht2;
	for (auto e : a2)
	{
		ht2.Insert({ e, e });
	}
	ht2.Insert({ 100, 100 });
	ht2.Insert({ 101, 101 });
}

int main()
{
	//test_HashTable();
	test_HashBucket();
	return 0;
}