#define _CRT_SECURE_NO_WARNINGS
#include"HashTable.h"

int main()
{
	//int a[] = { 19, 30, 52, 63, 11, 22 };
	int a[] = { 19,30,5,36,13,20,21,12 };
	HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert({ e, e });
	}

	ht.Erase(30);
	if (ht.Find(20))
	{
		cout << "Find!!" << endl;
	}

	if (ht.Find(30))
	{
		cout << "Find it!!" << endl;
	}
	else
	{
		cout << "Not Find it!!" << endl;
	}

	return 0;
}