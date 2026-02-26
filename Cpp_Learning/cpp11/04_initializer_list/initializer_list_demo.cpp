// File: cpp11/04_initializer_list/initializer_list_demo.cpp
// Topic: C++11 initializer_list - Uniform container initialization
// From yuuki's C++11 blog series

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    // Traditional way (multiple push_back / constructors)
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    // C++11 braced-init-list (most concise)
    vector<int> v2{ 1, 2, 3 };           // direct braced-init
    vector<int> v3 = { 10, 20, 30 };     // copy-list-initialization
    const vector<int>& v4{ 10, 20, 30 }; // reference to temporary (lifetime extended)

    // map with braced-init-list (initializer_list<pair<const K, V>>)
    map<string, string> dict{
        {"sort",   "ÅÅÐò"},
        {"string", "×Ö·û´®"},
        {"insert", "²åÈë"}
    };

    // Custom class that supports initializer_list (optional advanced demo)
    // (not in your blog, but good to know)
    cout << "vector v2 size: " << v2.size() << endl;  // 3
    cout << "map dict size: " << dict.size() << endl; // 3

    // Output map content
    for (const auto& p : dict) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}