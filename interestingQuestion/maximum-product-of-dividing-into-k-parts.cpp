#include "../include/DisplayHelper.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

#define MOD 1'000'000'007

class Solution {
private:
    vector<vector<int>> dp;

public:

    Solution() {

    }

    Solution(int N) {
        dp.assign(N + 1, vector<int>(N + 1, -1));
    }

    /*
     * n: 数
     * k: 需要分成多少份
     */
    int solver(int n, int k) {
        int a = n / k;
        int b = n % k;
        return (quick_pow(a, k - b, MOD) * quick_pow(a + 1, b, MOD)) % MOD;
    }

    int solver_check(int n, int k) { // 暴力解法
        if (dp[n][k] != -1) return dp[n][k];
        dp[n][k] = helper_check(n, k);
        return dp[n][k];
    }

    int helper_check(int n, int k) {
        if (n == k) return 1; // 特例
        if (k == 1) return n % MOD; // 只有一份就是自己

        if (dp[n][k] != -1) return dp[n][k]; // 记忆化存储
        int ans = INT_MIN;
        for (int i = 1; i < n - 1 && (n - i) >= (k - 1) /* 只有这样才能有增长,否则某一个数必然无法分到1 */; i++) {
            ans = max( ans,
                     ( i * helper_check(n - i, k - 1) ) % MOD );
        }
        dp[n][k] = ans;
        return dp[n][k];
    }

    int quick_pow(int a, int b, int mod) {
        if (b == 0) return 1; if (a == 0) return 0;

        int ans = 1;
        while (b) {
            if (b & 1) ans = ( ans * a ) % MOD ;
            a = ( a * a ) % MOD;
            b /= 2;
        }
        return ans;
    }
};

int random_int(int min, int max) {
    static random_device rd;
    static mt19937  gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    int N = 50;
    int testTimes = 2000;
    auto sol = Solution(N);
    cout << "Test start" << endl;
    for (int i = 1; i <= testTimes; i++) {
        int n = random_int(1, N);
        int k = random_int(1, n);
        int ans1 = sol.solver(n, k);
        int ans2 = sol.solver_check(n, k);
        if (ans1 != ans2) {
            display::print_fmt("[Wrong] n: {0}, k: {1}", n, k); // 错的时候需要打印出当前的n k
            // 边界处理不干净
        }
        if (i % 100 == 0) display::print_fmt("Test to {0} turns", i);
    }
    cout << "Test finished" << endl;
}