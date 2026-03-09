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

	~Date()
	{
		cout << "~Date()" << endl;
	}

	//private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};

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
		//-----------------------------------------------------------------------
		// 版本1：支持单参数
			// sp1 默认构造生成 _pcount 计数为 1（有1个模板参数）
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{
		}		// 这里可能会因为没有调用 del 而报错，所以下面写了 lambda 作为缺省值去默认构造 del

	 // shared_ptr 删除器写法(有2个模板参数)
		template<class D> // D = delete
		shared_ptr(T* ptr, D del) // 包装器：del 传到默认构造去，D 可能是 lambda、仿函数、函数指针
			:_ptr(ptr)
			, _pcount(new int(1))
			, _del(del) // 难点：需要把删除器保存下来(因为D是构造函数的模板参数，所以定义不了)
		{
		}

		// 版本2：支持双参数
			// sp2(sp1) _pcount 计数需++
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			(*_pcount)++;
		}
		//-----------------------------------------------------------------------


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

int main()
{
	yuuki::shared_ptr<Date> sp1(new Date); // 这里会因没有调用到 del 而程序崩溃

	// 定制删除器
	yuuki::shared_ptr<Date> sp2(new Date[10], [](Date* ptr) {delete[] ptr; });

	return 0;
}