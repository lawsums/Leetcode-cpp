// 2025/9/28
#include <DisplayHelper.h>
#include <bits/stdc++.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;

class SortedStack {
private:
    int size = 0;
    stack<int> stk;
    stack<int> tmp;

public:
    SortedStack() {

    }

    void push(int val) {
        int max = stk.empty() ? INT_MAX : stk.top();
        int min = tmp.empty() ? INT_MIN : tmp.top();
        while (true) {
            if (val > max) {
                tmp.push(stk.top()); stk.pop();
                max = stk.empty() ? INT_MAX : stk.top();
            } else if (val < min) {
                stk.push(tmp.top()); tmp.pop();
                min = tmp.empty() ? INT_MIN : tmp.top();
            } else {
                stk.push(val);
                break;
            }
        }
        size++;
    }

    void pop() {
        if (size == 0) return;

        while (!tmp.empty()) {
            stk.push(tmp.top()); tmp.pop();
        }
        stk.pop();
        size--;
    }

    int peek() {
        if (size == 0) return -1;

        while (!tmp.empty()) {
            stk.push(tmp.top()); tmp.pop();
        }
        return stk.top();
    }

    bool isEmpty() {
        return size == 0;
    }
};


int main() {
}