#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class MyStack {
private:
    int logicalSize = 0; // top/bottum
    int* elems = new int[100'001]; // 开的内存要足够大

public:
    MyStack() {}

    void push(int val) {
        elems[logicalSize++] = val;
    }

    int query() {
        if (logicalSize == 0) {
            cout << "Empty" << endl;
            return -1;
        }
        cout << elems[logicalSize - 1] << endl;
        return elems[logicalSize - 1];
    }

    int pop() {
        if (logicalSize == 0) {
            cout << "Empty" << endl;
            return -1;
        }
        return elems[--logicalSize];
    }

    int size() {
        cout << logicalSize << endl;
        return logicalSize;
    }

};

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符

    MyStack stk = MyStack();
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;
        vector<string> query;
        while (ss >> token) {
            query.push_back(token);
        }
        
        if (query[0] == "push") {
            stk.push(stoi(query[1]));
        } else if (query[0] == "pop") {
            stk.pop();
        } else if (query[0] == "query") {
            stk.query();
        } else if (query[0] == "size") {
            stk.size();
        }
    }
}
// 64 位输出请用 printf("%lld")