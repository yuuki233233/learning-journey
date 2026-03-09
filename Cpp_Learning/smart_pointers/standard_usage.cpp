#include <iostream>
#include <memory>
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
		std::cout << "~Date()" << std::endl;
	}

	//private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};

int main() {
    // unique_ptr
	unique_ptr<Date> up1(new Date(2026, 3, 6));
	cout << up1->_year << std::endl;
	unique_ptr<Date> up3(move(up1));
	cout << up3->_year << std::endl;

    // shared_ptr
	shared_ptr<Date> sp1(new Date);
	shared_ptr<Date> sp2(sp1);
	shared_ptr<Date> sp3(sp2);
	cout << sp1.use_count() << std::endl;  // 3

    // weak_ptr
    std::weak_ptr<Date> wp = sp1;
    if (auto locked = wp.lock()) {
        std::cout << "Still alive: " << locked->_year << std::endl;
    }

    return 0;
}