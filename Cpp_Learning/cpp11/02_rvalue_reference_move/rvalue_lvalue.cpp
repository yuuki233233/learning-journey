// File: cpp11/02_rvalue_reference_move/rvalue_lvalue.cpp
// Topic: C++11 Lambda Expressions - Basic Syntax and Capture
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

    f(i1);          // lvalue reference
    f(i2);          // const lvalue reference
    f(3);           // rvalue reference
    f(move(i1));    // force rvalue reference

    // rvalue reference variable acts as lvalue in expressions
    int&& rr = 10;
    f(rr);          // lvalue reference (rr is named ¡ú lvalue)
    f(move(rr));    // rvalue reference again

    // reference lifetime extension
    const string& s1 = string("temp") + " more";  // extends temporary lifetime
    // s1 += "test";  // error: const reference cannot modify

    string&& s2 = string("temp") + " more";
    s2 += " modified";  // OK, non-const rvalue reference can modify
    cout << s2 << endl;

    return 0;
}