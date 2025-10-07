// 2025-08-28 22:10:47
#include <string>
#include <cmath>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

//Given two strings a and b, return the minimum number of times you should 
//repeat string a so that string b is a substring of it. If it is impossible for b to 
//be a substring of a after repeating it, return -1. 
//
// Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and 
//repeated 2 times is "abcabc". 
//
// 
// Example 1: 
//
// 
//Input: a = "abcd", b = "cdabcdab"
//Output: 3
//Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b 
//is a substring of it.
// 
//
// Example 2: 
//
// 
//Input: a = "a", b = "aa"
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// 1 <= a.length, b.length <= 10⁴ 
// a and b consist of lowercase English letters. 
// 
//
// Related Topics 字符串 字符串匹配 👍 348 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
typedef long long ll;

class Solution {
private:
    ll base = 499;
    const ll MOD = 1000000007; // 或 1000000009

public:
    int repeatedStringMatch(string a, string b) {
        if (a.find(b) != string::npos) {
            return 1;
        }

        int n = a.size(), m = b.size();
        int cur = 0, ans = 0;
        for (int i = n - 2; i >=  0; i--) {
            int tmp1 = substring_hash(a, (n - 1) - i, n - 1);
            int tmp2 = substring_hash(b, 0, i);
            /*
             *
             * 这里访问b出界了
             *
             */

            if (tmp1 == tmp2) {
                cur += i + 1;
                ans++;
                break;
            }
        } // 前面的部分处理完毕
        while (cur + n < m) {
            int tmp1 = string_hash(a);
            int tmp2 = substring_hash(b, cur, cur + n - 1);
            if (tmp1 == tmp2) {
                cur += n;
                ans++;
            } else {
                return -1;
            }
        } // 中间的部分处理完毕
        int res = m - cur;
        // 处理后面的部分
        // (只要检测剩下的部分是不是匹配的上即可)
        int tmp1 = substring_hash(a, 0, res - 1);
        int tmp2 = substring_hash(b, cur, m - 1);
        if (tmp1 == tmp2)
             return ans + 1;
        else return -1;
    }

private:
    int mapping(char c) {
        if (isdigit(c)) {
            return c - '0' + 1;
        } else if ('a' <= c && c <= 'z') {
            return c - 'a' + 11;
        } else if ('A' <= c && c <= 'Z') {
            return c - 'A' + 37;
        }
        // 题目没有要求其他字符
        return -1;
    }

    ll mod_pow(ll base, ll exp, ll mod) {
        ll result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    ll string_hash(const string& s) {
        ll ans = 0;
        for (char c : s) {
            ans = (ans * base + mapping(c)) % MOD;
        }
        return ans;
    }

    ll substring_hash(const string& s, int l, int r) {
        ll left = 0, right = 0;
        for (int i = 0; i < l; i++) {
            left = (left * base + mapping(s[i])) % MOD;
        }
        for (int i = 0; i <= r; i++) {
            right = (right * base + mapping(s[i])) % MOD;
        }
        ll power = mod_pow(base, r - l + 1, MOD);
        ll hash = (right - (left * power) % MOD + MOD) % MOD; // 防负数
        return hash;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    string a = "abcd", b = "cdabcdab";
    cout << Solution().repeatedStringMatch(a, b) << endl;
}