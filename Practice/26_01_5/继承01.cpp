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

//// 基类
//class Person
//{
//protected:
//	string _name = "yuuki";
//	int _num = 18;
//};
//
//// 派生类
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "Student身份证号：" << _num << endl;
//		cout << "Person身份证号 ：" << Person::_num << endl;
//	}
//protected:
//	int _num = 999;
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//
//	return 0;
//}


// ------------------->>>>>>>>>>>>>>> // 派生类的4个重要默认成员函数

class Person
{
public:

	/*默认构造第一种情况*/

	//// 默认构造(有初始化)
	//Person(const char* name = "YUUKI")
	//	:_name(name)
	//{
	//	cout << "Person()" << endl;
	//}


	/*默认构造第二种情况,需要子类帮助*/

	// 默认构造(无初始化)
	Person(const char* name)
		:_name(name)
	{
		cout << "Person()" << endl;
	}

	// 拷贝构造
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	// 赋值运算符重载
	Person& operator=(const Person& p)
	{
		cout << "Person& operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	// 析构函数
	~Person()
	{
		cout << "~Person" << endl;
	}
protected:
	string _name;
};

class Student : public Person
{
public:
	// 默认生成的构造函数的行为
	// 1、内置类型->不确定
	// 2、自定义类型->调用默认构造
	// 3、继承父类成员看做一个整体对象，调用父类的默认构造

	// 子类默认构造函数,
	Student(const char* name, int num, const char* addrss)
		// 将Person看做一个整体
		:Person(name)// 错误写法  ->  :_name(name)
		,_num(num)
		,_addrss(addrss)
	{}

	// 报错：因为父类和子类改成隐藏，直接调用子类，导致栈溢出
	/*Student& operator=(const Student& s)
	{
		operator=(s);
	}*/

	~Student()
	{
		// 错误写法: ~Person();
		// 原因:
		// 1. 语法定义，先子类后父类。如果写成上面，就成了先父类再子类
		// 2. 子类析构完后，编译器会自动掉用父类的析构
	}
protected:
	// 无缺省值
	/*int _num;
	string _addrss;*/

	// 有缺省值
	int _num = 18;
	string _addrss = "广东佛山市";
};

int main()
{
	Student s1("yuuki", 18, "广东佛山市");
	Student s2(s1);

	Student s3("YUUKI", 28, "广东深圳市");
	s1 = s3; // 不需要在子类写赋值运算符,只需要父类里写即可

	return 0;
}