#define MOD 1'000'000'007
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> fact;

public:
    Solution() {
        fact.assign(1'000'001, -1);
        fact[0] = 1;
        fact[1] = 1;
    }

    int Factorial(int n) {
        if (n < 0) return 0; // 处理负数输入
        if (fact[n] != -1) return fact[n];
        fact[n] = (1LL * n * Factorial(n - 1)) % MOD;
        return fact[n];
    }
};

int main() {
    int n;
    cin >> n;
    
    auto sol = Solution();
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << sol.Factorial(a) << endl;
    }
    
    return 0;
}
