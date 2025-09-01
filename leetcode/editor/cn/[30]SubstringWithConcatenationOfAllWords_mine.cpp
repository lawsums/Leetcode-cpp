// 2025-08-28 15:41:02
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * 1.没用到ull的自然溢出(修复)
 * 2.没用构造powed数组,导致效率依然没有实现O(1)
 * 3.滑动窗口逻辑错误
 */

//leetcode submit region begin(Prohibit modification and deletion)
typedef unsigned long long ull;

class Solution {
private:
    ull base = 499;
    const ull MOD = 1000000007; // 或 1000000009
    vector<ull> hashed;

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        hashed.assign(s.size(), 0);
        build(s);

        int n = words.size(), m = words[0].size();
        int dept = 0;
        vector<int> ans;
        unordered_map<ull, int> mp;

        for (const auto & word : words) { // 开始欠债
            mp[hash(word)]++; // 迁移string_hash
            dept++;
        }

        for (int k = 0; k < m; k++) { // 设置偏移量
            for (int l = k, r = k; r < s.size(); r += m) {
                // 如果mp中该子串数量大于0,说明需要还债
                if (mp[hash(r, r + m - 1)]++ > 0) { // 迁移substring_hash 同时实现记忆化
                    dept--;
                }

                while (l < r && (dept < 0 || (r - l + 1) >= n * m)) { // 如果窗口大小大于等于,需要缩小窗口
                    if ((r - l + 1) >= n * m && dept == 0) ans.push_back(l); // 更新答案
                    if (mp[hash(l, l + m - 1)] >= 0) { // 大于等于0的说明原先欠债
                        dept++;
                    }
                    l += m;
                }

            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

private:
    void build(const string& s) {
        ull ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = (ans * base + mapping(s[i])) % MOD;
            hashed[i] = ans;
        }
    }

    ull hash(int l, int r) {
        if (l <= 0) return hashed[r];
        return hashed[r] -
               hashed[l - 1] * mod_pow(base, r - l + 1, MOD);
    }

    ull mod_pow(ull base, ull exp, ull mod) {
        ull result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    ull hash(const string& s) {
        ull ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = (ans * base + mapping(s[i])) % MOD;
        }
        return ans;
    }

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

};
//leetcode submit region end(Prohibit modification and deletion)
