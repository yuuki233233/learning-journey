// File: cpp11/02_rvalue_reference_move/reference_overload_lifetime.cpp
// Topic: C++11 rvalue reference overload + lifetime extension
// From yuuki's C++11 blog series

#include <iostream>
#include <string>
#include <utility>  // std::move
using namespace std;

void f(int& x) { cout << "lvalue reference overload" << endl; }
void f(const int& x) { cout << "const lvalue reference overload" << endl; }
void f(int&& x) { cout << "rvalue reference overload" << endl; }

int main() {
    int i1 = 1;
    const int i2 = 2;

    // overload resolution
    f(i1);        // lvalue ¡ú int&
    f(i2);        // const lvalue ¡ú const int&
    f(3);         // rvalue ¡ú int&&
    f(move(i1));  // lvalue forced to rvalue ¡ú int&&

    // rvalue ref variable is lvalue in expressions
    int&& rr = 10;
    f(rr);        // rr is named ¡ú lvalue reference overload
    f(move(rr));  // force rvalue again

    // lifetime extension with const reference
    string temp = "hello";
    const string& s1 = temp + " world";  // temporary lifetime extended
    cout << s1 << endl;                  // "hello world"

    // non-const rvalue ref can modify
    string&& s2 = temp + " world";
    s2 += " modified";
    cout << s2 << endl;  // "hello world modified"

    return 0;
}