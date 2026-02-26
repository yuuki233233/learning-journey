#define _CRT_SECURE_NO_WARNIN
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

#include"模拟实现Queue.h"
#include"模拟实现Stack.h"
#include"PriorityQueue.h"

//int main()
//{
//	//yuuki::stack<int, vector<int>> st;
//	//yuuki::stack<int, list<int>> st;
//	yuuki::stack<int, vector<int>> st;
//
//	// 类模板实例化时，按需实例化，使用哪些成员函数就实列化哪些，不会全实列化
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	cout << st.top() << endl; // 4
//	st.pop(); 
//
//	//yuuki::queue<int, list<int>> q;
//	yuuki::queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	cout << q.front() << endl; // 1
//	q.pop();
//
//	return 0;
//}

//void test_op2()
//{
//	srand(time(0));
//	const int N = 1000000;
//
//	deque<int> dq1;
//	deque<int> dq2;
//
//	for (int i = 0; i < N; ++i)
//	{
//		auto e = rand() + i;
//		dq1.push_back(e);
//		dq2.push_back(e);
//	}
//
//	int begin1 = clock();
//	sort(dq1.begin(), dq1.end());
//	int end1 = clock();
//
//	int begin2 = clock();
//	// 拷贝到vector
//	vector<int> v(dq2.begin(), dq2.end());
//	sort(v.begin(), v.end());
//	dq2.assign(v.begin(), v.end());
//	int end2 = clock();
//
//	printf("deque sort:%d\n", end1 - begin1);
//	printf("deque copy vector sort, copy back deque:%d\n", end2 - begin2);
//}
//
//int main()
//{
//	test_op2();
//
//	return 0;
//}

int main()
{
	yuuki::priorityqueue<int, list<int>> pq;
	pq.push_back(6);
	pq.push_back(3);
	pq.push_back(8);
	pq.push_back(2);
	pq.push_back(9);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	return 0;
}

// 仿函数：本质是一个类，这个类重载operator(),他的对象可以像函数一样使用
//template<class T>
//class Less
//{
//public:
//	bool operator()(const T& x, const T& y)
//	{
//		return x < y;
//	}
//};
//
//template<class T>
//class Greater
//{
//public:
//	bool operator()(const T& x, const T& y)
//	{
//		return x > y;
//	}
//};

//template<class Compare>
//void BubbleSort(int* a, int n, Compare com)
//{
//	for (int j = 0; j < n; j++)
//	{
//		// 单趟
//		int flag = 0;
//		for (int i = 1; i < n - j; i++)
//		{
//			//if (a[i] < a[i - 1])
//			if (com(a[i], a[i - 1]))
//			{
//				swap(a[i - 1], a[i]);
//				flag = 1;
//			}
//		}
//
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//
//template<class T>
//void print(T* a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i];
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Less<int> LessFunc;
//	Greater<int> GreaterFunc;
//	// 函数对象
//	cout << LessFunc(1, 2) << endl;
//	cout << LessFunc.operator()(1, 2) << endl;
//
//	int a[] = { 9,1,2,5,7,4,6,3 };
//	BubbleSort(a, 8, LessFunc);
//	cout << "LessFunc:";
//	print(a, sizeof(a) / sizeof(a[0]));
//	cout << endl;
//
//	BubbleSort(a, 8, GreaterFunc);
//	cout << "GreaterFunc:";
//	print(a, sizeof(a) / sizeof(a[0]));
//	cout << endl;
//
//	BubbleSort(a, 8, Less<int>());
//	cout << "LessFunc:";
//	print(a, sizeof(a) / sizeof(a[0]));
//	cout << endl;
//
//	BubbleSort(a, 8, Greater<int>());
//	cout << "GreaterFunc:";
//	print(a, sizeof(a) / sizeof(a[0]));
//	cout << endl;
//
//	return 0;
//}