// File: cpp11/01_uniform_initialization/uniform_initialization.cpp
// Topic: C++11 Lambda Expressions - Basic Syntax and Capture
// From yuuki's C++11 blog series

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Point {
    int x;
    int y;
};

class Date {
public:
    Date(int year = 1, int month = 1, int day = 1)
        : year_(year), month_(month), day_(day) {
        cout << "Date() - direct construction" << endl;
    }

    Date(const Date& d)
        : year_(d.year_), month_(d.month_), day_(d.day_) {
        cout << "Date(const Date&) - copy construction" << endl;
    }

private:
    int year_;
    int month_;
    int day_;
};

int main() {
    // C++98 style
    int a1[] = { 1, 2, 3 };
    Point p = { 1, 2 };
    Date d = 2026;  // implicit conversion

    // C++11 uniform initialization with {}
    int x1{ 2 };                  // built-in type
    Point p1{ 1, 2 };             // aggregate initialization
    Date d1{ 2025, 1, 1 };        // direct initialization (may elide copy)
    const Date& d2{ 2025, 1, 1 }; // reference binding to temporary

    // vector initialization
    vector<Date> v;
    v.push_back(d1);                    // named object
    v.push_back(Date{ 2025, 1, 1 });      // temporary object
    v.push_back({ 2025, 1, 1 });          // braced-init-list (most concise)

    cout << "All Date objects created." << endl;
    return 0;
}