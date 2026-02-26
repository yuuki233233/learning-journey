#define _CRT_SECURE_NO_WARNINGS
#include"Hash.h"

int main()
{
	HashTable<int, int> hash;

	//int a[] = { 19,30,52,63,11,22 };
	int a[] = { 19,30,5,36,13,20,21,12 };
	
	for (auto e : a)
	{
		hash.Insert({ e, e });
	}

	hash.Insert({ 15, 15 });


	hash.Erase(30);

	if (hash.Find(20))
	{
		cout << "ур╣╫ак" << endl;
	}


	return 0;
}