// File: cpp11/03_lambda/lambda_stl_function.cpp
// Topic: C++11 Lambda in STL + std::function + std::bind
// From yuuki's C++11 blog series

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <stack>
#include <string>
using namespace std;

// Example: lambda as comparator
void sort_demo() {
    vector<int> v = { 5, 2, 9, 1, 5, 6 };
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });  // descending
    cout << "Sorted descending: ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

// Example: reverse Polish notation (RPN) evaluator with lambda + map + function
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    map<string, function<int(int, int)>> opMap = {
        {"+",  [](int x, int y) { return x + y; }},
        {"-",  [](int x, int y) { return x - y; }},
        {"*",  [](int x, int y) { return x * y; }},
        {"/",  [](int x, int y) { return x / y; }}
    };

    for (auto& token : tokens) {
        if (opMap.count(token)) {
            int right = st.top(); st.pop();
            int left = st.top(); st.pop();
            st.push(opMap[token](left, right));
        }
        else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

int main() {
    sort_demo();

    // RPN test
    vector<string> tokens = { "2", "1", "+", "3", "*" };
    cout << "RPN result (2 + 1) * 3 = " << evalRPN(tokens) << endl;  // 9

    return 0;
}