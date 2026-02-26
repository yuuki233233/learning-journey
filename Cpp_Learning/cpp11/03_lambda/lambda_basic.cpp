// File: cpp11/03_lambda/lambda_basic.cpp
// Topic: C++11 Lambda Expressions - Basic Syntax and Capture
// From yuuki's C++11 blog series

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // basic syntax
    auto add = [](int a, int b) { return a + b; };
    cout << add(3, 4) << endl;  // 7

    // with capture
    int count = 0;
    auto inc = [count]() mutable {
        ++count;
        cout << "inside lambda: " << count << endl;
        };
    inc();  // 1
    inc();  // 2
    cout << "outside: " << count << endl;  // 0 (only copy modified)

    // STL usage
    vector<int> v = { 5, 2, 9, 1, 5, 6 };
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });  // descending
    for (int x : v) cout << x << " ";
    cout << endl;

    return 0;
}