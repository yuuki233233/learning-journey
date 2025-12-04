//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s1("hello world");
//
//	// 下标 + []		
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//string类常用接口/访问及遍历/

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s1("hello world");
//
//	//正向迭代器
//	//string::iterator it = s1.begin();
//	auto it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	
//	//反向迭代器
//	//string::reverse_iterator rit = s1.rbegin();
//	auto rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	const string s2("hello world");
//	//const正向迭代器
//	//string::const_iterator cit = s2.begin();
//	auto cit = s2.begin();
//	while (cit != s2.end())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//
//	//const反向迭代器
//	//string::const_reverse_iterator rcit = s2.rbegin();
//	auto rcit = s2.rbegin();
//	while (rcit != s2.rend())
//	{
//		cout << *rcit << " ";
//		++rcit;
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<list>
//using namespace std;
//
//int main()
//{
//	list<int> lt{ 1,2,3,4,5 };
//	list<int>::iterator lit = lt.begin();
//	while (lit != lt.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//
//	//赋值，自动迭代，自动判断结束(底层还是迭代器)
//	for (auto li : lt)
//	{
//		cout << li << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int func1()
//{
//	return 10;
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = func1();
//
//
//	//auto必须初始化
//	//auto e;
//
//
//	//识别auto类型
//	cout << typeid(b).name() << endl; //int
//	cout << typeid(c).name() << endl; //char
//	cout << typeid(d).name() << endl; //int
//	
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	//C++98遍历
//	int array1[] = { 1,2,3,4,5 };
//	for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
//	{
//		array1[i] *= 2;
//	}
//	for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
//	{
//		cout << array1[i] << " ";
//	}
//	cout << endl;
//
//
//	//C++11遍历
//	int array2[] = { 1,2,3,4,5 };
//	for (auto& e : array2)
//		e *= 2;
//
//	for (auto& e : array2)
//		cout << e << " ";
//	cout << endl;
//
//	string str("hello world");
//	for (auto ch : str)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


////string类的常用接口
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	//构造空的string类对象，即空字符串
//	string s1;
//
//	//用C-string来构造string类对象
//	string s2("hello world");
//
//	//拷贝构造函数
//	string s3(s2);
//	cin >> s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;  //11
//	cout << s1.empty() << endl; //0
//	s1.clear();
//	cout << s1 << endl; //打印空
//
//	string s2;
//	s2.reserve(100);
//	cout << s2.capacity() << endl; //111
//
//	//左(要初始化个数)：右(初始化的字符)
//	s2.resize(4, 'c');
//	cout << s2 << endl; //cccc
//
//	return 0;
//}