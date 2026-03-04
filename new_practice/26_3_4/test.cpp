#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<memory>
using namespace std;

class Date
{
public:
	Date(int year = 2026, int month = 3, int day = 4)
		:_year(year)
		,_month(month)
		,_day(day)
	{ }

	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{ }

	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

//private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};

// 模拟实现 unique_ptr
namespace yuuki
{
	template<class T>
	class unique_ptr
	{
	public:
		// 默认构造
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{ }

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete[]:" << _ptr << endl;
				delete _ptr;
			}
		}

		// 支持 自定义类型 和 pair类型
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// unique_ptr 不支持左值，需 delete
		unique_ptr(const unique_ptr<T>& sp) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;

		// unique_ptr 支持右值
		// 为什么移动构造没有 delete[] _ptr，因为 sp4 是新建的，_ptr 没有申请内存
		unique_ptr(unique_ptr<T>&& sp)
			:_ptr(sp._ptr)
		{
			sp._ptr = nullptr;
		}

		unique_ptr<T>& operator=(unique_ptr<T>&& sp)
		{
			// sp1 = sp3，sp1 中的 _ptr 存在数据，需要 delete
			delete _ptr;
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}

	private:
		T* _ptr;
	};
}

#include<functional>
namespace yuuki
{
	// 因为类里面访问不了构造函数的模板参数
	// 所以 unique_ptr 实现成 template<class T, class D>
	// 用删除器时必须传类型，用 lambda 时就特别不方便
	template<class T>
	class shared_ptr
	{
	public:
		// sp1 默认构造生成 _pcount 计数为 1（有1个模板参数）
		shared_ptr(T* ptr)
			:_ptr(ptr)
			,_pcount(new int(1))
		{ }		// 这里可能会因为没有调用 del 而报错，所以下面写了 lambda 作为缺省值去默认构造 del

		// shared_ptr 删除器写法(有2个模板参数)
		template<class D> // D = delete
		shared_ptr(T* ptr, D del) // 包装器：del 传到默认构造去，D 可能是 lambda、仿函数、函数指针
			:_ptr(ptr)
			,_pcount(new int(1))
			,_del(del) // 难点：需要把删除器保存下来(因为D是构造函数的模板参数，所以定义不了)
		{ }

		// sp2(sp1) _pcount 计数需++
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_pcount(sp._pcount)
		{
			(*_pcount)++;
		}

		//// sp1 = sp4  sp5 = sp4  sp1 = sp2
		//shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		//{
		//	if (_ptr != sp._ptr)
		//	{
		//		if (_ptr)
		//		{
		//			delete _ptr;
		//			delete _pcount;
		//		}
		//		_ptr = sp._ptr;
		//		_pcount = sp._pcount;
		//		(*_pcount)++;
		//	}
		//	else
		//	{
		//		return *this;
		//	}
		//	
		//	return *this;
		//}

		// shared_ptr 现代写法
		shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
			if (this != &sp) {  // 防止自赋值
				if (_ptr != sp._ptr) {  // 防止指向同一块内存（可选，但好习惯）
					if (--(*_pcount) == 0) {  // 计数减到0才释放
						delete _ptr;
						delete _pcount;
					}
					_ptr = sp._ptr;
					_pcount = sp._pcount;
					++(*_pcount);  // 新增引用计数
				}
			}
			return *this;
		}

		// 每次析构 sp2 _pcount 计数需--
		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				//delete _ptr;
				_del(_ptr);		// 传的是删除器，释放时用删除器释放
				delete _pcount;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// 修正 shared_ptr 中 use_count 的声明
		int use_count()
		{
			return (*_pcount);
		}

	private:
		T* _ptr;
		int* _pcount;
		//D _del; // 类里面用不了函数模板的参数

		// 包装器：del 传到默认构造去，D 可能是 lambda、仿函数、函数指针
		function<void(T*)> _del = [](T* ptr) { delete ptr; };
								// 传 lambda 缺省值，lambda 默认是 delete
								// 坑：delete[]，会导致程序死循环
	};
}

// 仿函数形式
template<class T>
void DeleteArrayFunc(T* ptr)
{
	delete[] ptr;
}

// 迭代器形式
template<class T>
class DeleteArray
{
public:
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

// 文件形式
class Fclose
{
public:
	void operator()(FILE* ptr)
	{
		cout << "fclose:" << ptr << endl;
		fclose(ptr);
	}
};

void main01()
{
	// 错误写法
	//unique_ptr<Date> up1(new Date[5]);
	//shared_ptr<Date> sp1(new Date[5]);

	/* 解决方法1 */
	// 日常经常使用 new[]，使用 unique_ptr 和 shared_ptr
	// 实现了哥特化版本，这个版本析构时用 delete[]
	unique_ptr<Date[]> up1(new Date[5]);
	shared_ptr<Date[]> sp1(new Date[5]);

	/* 解决方法2 */
	// 用定值删除器时，unique_ptr 和 shared_ptr 又不一样
	/*
	* unique_ptr 在类声明里传
	* template <class T, class D = default_delete<T>> class unique_ptr;
	* 
	* shared_ptr 在构造函数里面传
	* template <class U, class D> shared_ptr (U* p, D del);
	* 
	*/


	// 仿函数对象做删除器
	unique_ptr<Date, DeleteArray<Date>> up2(new Date[5]);
	shared_ptr<Date> sp2(new Date[5], DeleteArray<Date>());

	// 函数指针做删除器
	unique_ptr<Date, void(*)(Date*)> up3(new Date[5], DeleteArrayFunc<Date>);
	shared_ptr<Date> sp3(new Date[5], DeleteArrayFunc<Date>); // 仿函数需实例化

	// lambda表达式做删除器
	auto delArrOBJ = [](Date* ptr) {delete[] ptr; };
	unique_ptr<Date, decltype(delArrOBJ)> up4(new Date[5], delArrOBJ);
	shared_ptr<Date> sp4(new Date[5], [](Date* ptr) {delete[] ptr; }); // lambda 表达式做删除器

	// 实现其他资源管理器
	shared_ptr<FILE> sp5(fopen("test.cpp", "r"), Fclose());
	shared_ptr<FILE> sp6(fopen("test.cpp", "r"), [](FILE* ptr) {
		delete[] ptr;
		fclose(ptr);
		}); // 在函数参数传，实参传给形参通过模板自动推导 lambda 的类型
			// lambda、函数指针、仿函数都很好用

	unique_ptr<FILE, Fclose> up5(fopen("test.cpp", "r"));
	// 而 unique_ptr 必须传类型，但 lambda 拿不到类型，就很难用 lambda 写 unique_ptr
	// 这时候就可以用 decltype 关键字来推导类型
	auto fcloseFunc = [](FILE* ptr) {fclose(ptr); };
	unique_ptr<FILE, decltype(fcloseFunc)> up6(fopen("test.cpp", "r"), fcloseFunc);

	/*  总结
	* 如果用 unique_ptr 定制删除器，建议用仿函数
	* 如果用 shared_ptr 定制删除器，都可以，lambda 更好
	*/
	
}

void main02()
{
	yuuki::shared_ptr<Date> sp1(new Date);
	yuuki::shared_ptr<Date> sp2(sp1);
	// 调用拷贝构造，因为 sp3 不存在
	yuuki::shared_ptr<Date> sp3 = sp2;
	cout << "sp1.use_count()：" << sp1.use_count() << endl; // 3

	yuuki::shared_ptr<Date> sp4(new Date);
	cout << "sp4.use_count()：" << sp4.use_count() << endl; // 1


	sp1->_year++;
	cout << "sp1->_year：" << sp1->_year << endl; // 2027
	cout << "sp2->_year：" << sp2->_year << endl; // 2027
	cout << "sp3->_year：" << sp3->_year << endl; // 2027
	cout << "sp4->_year：" << sp4->_year << endl; // 2026


	/*
	* 赋值构造
	* 1. 对象不存在，拷贝构造
	* 2. 对象存在，赋值构造
	*/

	// 自己给自己赋值
	sp1 = sp2;
	cout << "sp1.use_count()：" << sp1.use_count() << endl; // 3


	// 对象不存在，拷贝构造
	yuuki::shared_ptr<Date> sp5 = sp4;
	cout << "sp5.use_count()：" << sp5.use_count() << endl; // 2

	// 对象存在，赋值构造
	sp4 = sp1;
	cout << "sp1.use_count()：" << sp1.use_count() << endl; // 4

	// 对象存在，赋值构造
	yuuki::shared_ptr<Date> sp6(new Date);
	sp1 = sp6;
	cout << "sp1.use_count()：" << sp1.use_count() << endl; // 2
}

void main03()
{
	yuuki::shared_ptr<Date> sp1(new Date);

	// 定制删除器
	yuuki::shared_ptr<Date> sp2(new Date[10], [](Date* ptr) {delete[] ptr; });
}

void main04()
{
	shared_ptr<Date> sp1(new Date(2026, 3, 4));

	// 先传日期类的参数，new 了个日期类对象交给 make_shared 管理
	// shared_ptr 每一个对象都会有引用计数，每一个引用计数都会向堆申请内存
	// 向堆申请大量的开小块内存，会有性能的消耗，碎片化的内存也会导致内存碎片的问题
	// 这时候就要用到内存池进行管理小块内存

	// make_shared 会在 Date 内存中多开 4bite 存引用计数
	// 这样只用开一次内存，make_shared 会高效一点点
	shared_ptr<Date> sp2 = make_shared<Date>(2026, 3, 4);
}

void main05()
{
	shared_ptr<Date> sp1(new Date(2026, 3, 4));
	shared_ptr<Date> sp2 = make_shared<Date>(2026, 3, 4);
	shared_ptr<Date> sp4;

	if (sp1)
		cout << "sp1 is not nullptr" << endl;

	if (sp2.operator bool()) // 原始版本为 operator bool
		cout << "sp2 if not nullptr" << endl;

	if (sp4)
		cout << "sp4 is not nullptr" << endl;

	// 报错：禁止使用隐式类型转换 + 拷贝构造
	//shared_ptr<Date> sp5 = new Date(2026, 3, 4);
	shared_ptr<Date> sp6(new Date(2026, 3, 4)); // 正确用法
}

int main()
{
	main04();

	return 0;
}