#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

#include"Myset.h"
#include"Mymap.h"


//void Print(const yuuki::set<int>& s)
//{
//	yuuki::set<int>::const_iterator it = s.end();
//	while (it != s.begin())
//	{
//		--it;
//		cout << *it << " ";
//	}
//	cout << endl;
//}

int main()
{
	yuuki::set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(6);

	yuuki::set<int>::iterator sit = s.begin();
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

	//Print(s);

	return 0;
}