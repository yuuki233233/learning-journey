#include<iostream>
#include<vector>
using namespace std;

namespace yuuki
{
    // 继承std::vector模板类实现栈
    template<class T>
    class stack : public std::vector<T>
    {
    public:
        void push(const T& x) {
            vector<T>::push_back(x); // 必须指定vector<T>域
        }
        void pop() {
            vector<T>::pop_back();
        }
        const T& top() {
            return vector<T>::back();
        }
        bool empty() {
            return vector<T>::empty();
        }
    };
}

int main()
{
    yuuki::stack<int> st;
    st.push(1); st.push(2); st.push(3);
    while (!st.empty()) {
        cout << st.top() << " "; // 输出：3 2 1
        st.pop();
    }
    return 0;
}