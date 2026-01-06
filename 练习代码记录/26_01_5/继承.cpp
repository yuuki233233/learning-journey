#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>原始写法
//// 学生
//class student
//{
//public:
//	// 进入校园/图书馆/刷二维码等身份验证
//	void identity()
//	{
//		// ...
//	}
//
//	// 学习
//	void study()
//	{
//		// ..
//	}
//
//protected:
//	string _name = "yuuki";	// 姓名
//	string _address;// 地址
//	string _tel;	// 电话
//	int _age = 18;	// 年龄
//
//	int _stuid;		// 学号
//};
//
//// 老师
//class Teacher
//{
//public:
//	// 进入校园/图书馆/刷二维码等身份验证
//	void identity()
//	{
//		// ...
//	}
//
//	// 授课
//	void teaching()
//	{
//		// ...
//	}
//protected:
//	string _name = "bit";	// 姓名
//	string _address;// 地址
//	string _tel;	// 电话
//	int _age = 33;	// 年龄
//
//	string _title;	// 职称
//};


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 继承写法

//// 学生老师共有部分
//class Person
//{
//public:
//	// 进入校园/图书馆/刷二维码等身份验证 (共有部分)
//	void identity()
//	{
//		cout << "voie identity()" << _name << endl;
//	}
//protected:
//	string _name = "yuuki";
//	string _address;
//	string _tel;
//	int _age = 18;
//};
//
//// 学生不同部分
//class Student : public Person
//{
//public:
//	// 学习
//	void study()
//	{
//		// ..
//	}
//protected:
//	int _stuid;
//};
//
//// 老师不同部分
//class Teacher : public Person
//{
//public:
//	// 授课
//	void teaching()
//	{
//		// ...
//	}
//protected:
//	string title;
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//
//	s.identity();
//	t.identity();
//
//	return 0;
//}


// ----------->>>>>>>>>>>>>>>>>>>>>> // 继承类模板

//#include<vector>
//namespace yuuki
//{
//	template<class T>
//	class stack : public std::vector<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			// 基类是模板时，要指定类域，不然找不到
//			// 因为stack<int>实例化时，也实例化vector<int>
//			vector<T>::push_back(x);
//		}
//
//		void pop()
//		{
//			vector<T>::pop_back();
//		}
//
//		const T& top()
//		{
//			return vector<T>::back();
//		}
//
//		bool empty()
//		{
//			return vector<T>::empty();
//		}
//	};
//}
//
//int main()
//{
//	yuuki::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//
//	return 0;
//}


// ---------------------->>>>>>>>>>>>> // 切片

//// 基类(共有部分)
//class Person
//{
//	// 虚函数(跟后面学的多态有关系)
//	virtual void func()
//	{ }
//
//protected:
//	string _name;
//	string _sex;
//	int _age;
//};
//
//// 派生类
//class Student : public Person
//{
//public:
//	int _Stdid;
//};
//
//int main()
//{
//	Student sobj;
//	// 1.派生类对象可以赋值给基类的指针/引用(中间没有产生临时变量)
//	// 所以基类可以直接引用派生对象
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	// 对比变量
//	int i = 1;
//	double d1 = i;
//	const double& d2 = i;
//
//	// 2.基类对象不能赋值给派生类对象
//	// sobj = pobj
//
//	// 后面再细说多态
//	Student* ps1 = dynamic_cast<Student*>(pp);
//	cout << ps1 << endl;
//
//	pp = &pobj;
//	Student* ps2 = dynamic_cast<Student*>(pp);
//	cout << ps2 << endl;
//
//	return 0;
//}


// -------------------->>>>>>>>>>>>> // 作用域的隐藏规则

// 基类
class Person
{
protected:
	string _name = "yuuki";
	int _num = 18;
};

// 派生类
class Student : public Person
{
public:
	void Print()
	{
		cout << "姓名：" << _name << endl;
		cout << "Student身份证号：" << _num << endl;
		cout << "Person身份证号 ：" << Person::_num << endl;
	}
protected:
	int _num = 999;
};

int main()
{
	Student s;
	s.Print();

	return 0;
}