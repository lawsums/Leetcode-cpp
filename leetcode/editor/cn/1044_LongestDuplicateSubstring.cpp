// 2025-08-29 12:12:20
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

//Given a string s, consider all duplicated substrings: (contiguous) substrings 
//of s that occur 2 or more times. The occurrences may overlap. 
//
// Return any duplicated substring that has the longest possible length. If s 
//does not have a duplicated substring, the answer is "". 
//
// 
// Example 1: 
// Input: s = "banana"
//Output: "ana"
// 
// Example 2: 
// Input: s = "abcd"
//Output: ""
// 
// 
// Constraints: 
//
// 
// 2 <= s.length <= 3 * 10⁴ 
// s consists of lowercase English letters. 
// 
//
// Related Topics 字符串 二分查找 后缀数组 滑动窗口 哈希函数 滚动哈希 👍 432 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
typedef unsigned long long ull;
const ull BASE = 499;

class Solution {
public:
    string longestDupSubstring(string s) {
        string ans = "";
        int n = s.size();

        build(s);

        unordered_map<ull, int> mp;
        for (int arrLen = n - 1; arrLen > 0; arrLen--) {
            // 对于每个情况进行滑动窗口
            for (int i = 0; i + arrLen <= n; i++) {
                ull tmp = hash(i, i + arrLen - 1);
                if (mp.count(tmp)) return s.substr(i, arrLen);
                mp[tmp]++;
            }
        }

        return ans;
    }

private:
    vector<ull> hashed;
    vector<ull> pow_arr;

private:
    void build(const string& s) {
        int n = s.size();
        hashed.resize(n);
        pow_arr.resize(n + 1);

        // 初始化幂数组
        pow_arr[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow_arr[i] = pow_arr[i - 1] * BASE; // 使用ull类型自然溢出
        }

        // 初始化哈希数组
        hashed[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++) {
            hashed[i] = hashed[i - 1] * BASE + (s[i] - 'a' + 1); // 自然溢出
        }
    }

    // 计算子串 s[l..r] 的哈希值
    ull hash(int l, int r) {
        if (l == 0) return hashed[r];
        return hashed[r] - hashed[l - 1] * pow_arr[r - l + 1];
    }

    // 计算整个字符串的哈希值
    ull hash(const string& str) {
        ull h = 0;
        for (char c : str) {
            h = h * BASE + (c - 'a' + 1);
        }
        return h;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution().longestDupSubstring("banana");
}