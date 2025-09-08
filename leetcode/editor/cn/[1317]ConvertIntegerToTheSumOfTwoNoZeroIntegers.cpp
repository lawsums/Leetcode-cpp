// 2025-09-08 10:24:26
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//No-Zero integer is a positive integer that does not contain any 0 in its 
//decimal representation. 
//
// Given an integer n, return a list of two integers [a, b] where: 
//
// 
// a and b are No-Zero integers. 
// a + b = n 
// 
//
// The test cases are generated so that there is at least one valid solution. 
//If there are many valid solutions, you can return any of them. 
//
// 
// Example 1: 
//
// 
//Input: n = 2
//Output: [1,1]
//Explanation: Let a = 1 and b = 1.
//Both a and b are no-zero integers, and a + b = 2 = n.
// 
//
// Example 2: 
//
// 
//Input: n = 11
//Output: [2,9]
//Explanation: Let a = 2 and b = 9.
//Both a and b are no-zero integers, and a + b = 11 = n.
//Note that there are other valid answers as [8, 3] that can be accepted.
// 
//
// 
// Constraints: 
//
// 
// 2 <= n <= 10⁴ 
// 
//
// Related Topics 数学 👍 47 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
typedef long long ll;
#define MOD 1'000'000'007

class QuickPower {
public:
    static ll pow(ll a, ll b, ll p) {
        if (p == 1) return 0; // 任何数模1都是0
        if (b == 0) return 1 % p; // 任何数的0次方都是1

        ll result = 1;
        a %= p; // 先取模防止溢出

        while (b > 0) {
            if (b & 1) { // 使用位运算判断奇偶，效率更高
                result = (result * a) % p;
            }
            a = (a * a) % p;
            b >>= 1; // 使用位运算代替除法
        }
        return result;
    }
};

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        // 个位不能和原先的相等
        // 减法
        int cnt = 0, borrow = 0, n_copy = n;
        int n_cur = 0, a_cur = 0, a = 0;
        while (n > 0) {
            n_cur = n % 10;
            if (n_cur == 0 || n_cur == 1) {
                if (n / 10) a_cur = 9;
                else a_cur = n;
            }
            else a_cur = n_cur - 1; // 防止和当前位相同

            a += a_cur * QuickPower::pow(10, cnt, MOD);
            if (a_cur > n_cur) borrow = 1;
            else borrow = 0;

            n /= 10;
            if (borrow) n -= 1;
            cnt++;
        }

        return {a, n_copy - a};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
