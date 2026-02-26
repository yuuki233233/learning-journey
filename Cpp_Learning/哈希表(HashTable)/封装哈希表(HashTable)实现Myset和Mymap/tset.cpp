#include<iostream>
using namespace std;

#include"UnorderedMap.h"
#include"UnorderedSet.h"
int main()
{
	yuuki::unorder_set<int> s;
	int a[] = {3,1,6,7,8,2,1,1,5,6,7,6};
	for (auto e : a)
	{
		s.insert(e);
	}

	yuuki::unorder_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	return 0;
}