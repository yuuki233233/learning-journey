#include<iostream>
#include<memory>
using namespace std;



class Date
{
public:
	Date(int year = 2026, int month = 3, int day = 4)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
	}

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
		{
		}

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

namespace yuuki
{
	template<class T>
	class shared_ptr
	{
	public:
		// sp1 默认构造生成 _pcount 计数为 1
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{
		}

		// sp2(sp1) _pcount 计数需++
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
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

		// sp1 = sp4  sp5 = sp4  sp1 = sp2
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
				delete _ptr;
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
	};
}

int main()
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

	return 0;
}

