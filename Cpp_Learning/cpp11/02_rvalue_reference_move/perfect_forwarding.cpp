// File: cpp11/02_rvalue_reference_move/perfect_forwarding.cpp
// Topic: C++11 Perfect Forwarding with universal references
// From yuuki's C++11 blog series

#include <iostream>
#include <string>
#include <utility>  // std::forward, std::move
using namespace std;

struct Person {
    string name;
    int age;

    Person(const string& n, int a) : name(n), age(a) {
        cout << "copy constructor" << endl;
    }

    Person(string&& n, int a) : name(move(n)), age(a) {
        cout << "move constructor" << endl;
    }
};

// Factory function with perfect forwarding
template<typename... Args>
Person make_person(Args&&... args) {
    // std::forward preserves lvalue/rvalue property
    return Person(forward<Args>(args)...);
}

int main() {
    string s = "Alice";
    make_person(s, 18);                     // lvalue ¡ú copy constructor
    make_person("Bob", 20);                 // rvalue string literal ¡ú move
    make_person(move(s), 25);               // explicit move ¡ú move constructor
    make_person(string("Charlie"), 22);     // temporary ¡ú move

    return 0;
}