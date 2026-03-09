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

int main()
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

	return 0;
}