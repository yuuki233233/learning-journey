// File: cpp11/02_rvalue_reference_move/move_constructor.cpp
// Topic: C++11 Lambda Expressions - Basic Syntax and Capture
// From yuuki's C++11 blog series

#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

class MyString {
public:
    MyString(const char* str = "") {
        size_ = strlen(str);
        capacity_ = size_;
        data_ = new char[capacity_ + 1];
        strcpy(data_, str);
        cout << "MyString() - constructor" << endl;
    }

    // copy constructor
    MyString(const MyString& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new char[capacity_ + 1];
        strcpy(data_, other.data_);
        cout << "MyString(const MyString&) - copy constructor" << endl;
    }

    // move constructor
    MyString(MyString&& other) noexcept {
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.size_ = other.capacity_ = 0;
        cout << "MyString(MyString&&) - move constructor" << endl;
    }

    ~MyString() {
        delete[] data_;
    }

private:
    char* data_;
    size_t size_;
    size_t capacity_;
};

int main() {
    MyString s1("hello world");
    MyString s2 = s1;               // copy
    MyString s3 = move(s1);         // move (s1 resources stolen)
    return 0;
}