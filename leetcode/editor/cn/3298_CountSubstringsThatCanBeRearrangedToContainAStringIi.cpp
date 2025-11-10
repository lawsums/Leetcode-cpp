// 2025-10-08 16:23:39
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//You are given two strings word1 and word2. 
//
// A string x is called valid if x can be rearranged to have word2 as a prefix. 
//
//
// Return the total number of valid substrings of word1. 
//
// Note that the memory limits in this problem are smaller than usual, so you 
//must implement a solution with a linear runtime complexity. 
//
// 
// Example 1: 
//
// 
// Input: word1 = "bcca", word2 = "abc" 
// 
//
// Output: 1 
//
// Explanation: 
//
// The only valid substring is "bcca" which can be rearranged to "abcc" having 
//"abc" as a prefix. 
//
// Example 2: 
//
// 
// Input: word1 = "abcabc", word2 = "abc" 
// 
//
// Output: 10 
//
// Explanation: 
//
// All the substrings except substrings of size 1 and size 2 are valid. 
//
// Example 3: 
//
// 
// Input: word1 = "abcabc", word2 = "aaabc" 
// 
//
// Output: 0 
//
// 
// Constraints: 
//
// 
// 1 <= word1.length <= 10⁶ 
// 1 <= word2.length <= 10⁴ 
// word1 and word2 consist only of lowercase English letters. 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 45 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long validSubstringCount(string s, string word2) {
        vector<int> cnts(26, 0);
        vector<int> path(26, 0);
        int need = word2.size();

        for (const auto c : word2) {
            cnts[c - 'a']++;
        }

        long long ans = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (path[s[r] - 'a'] < cnts[s[r] - 'a']) { need--; }
            path[s[r] - 'a']++;

            while (need == 0) { // 债还完了
                if (path[s[l] - 'a'] == cnts[s[l] - 'a']) need++; // 增加债务
                path[s[l++] - 'a']--; // 左边界右移
                ans += s.size() - r; // 更新答案
            }
        }

        return ans;
    }
};

//class Solution {
//public:
//    long long validSubstringCount(string s, string word2) {
//        if (word2.empty()) return 0;
//
//        vector<int> cnts(26, 0);
//        vector<int> path(26, 0);
//        int need = word2.size();
//
//        for (const auto c : word2) {
//            cnts[c - 'a']++;
//        }
//
//        long long ans = 0;
//        for (int l = 0, r = 0; r < s.size(); r++) {
//            // 扩展右边界
//            if (path[s[r] - 'a'] < cnts[s[r] - 'a']) {
//                need--;
//            }
//            path[s[r] - 'a']++;
//
//            // 收缩左边界
//            while (need == 0) {
//                // 先计算答案（关键：在收缩前计算）
//                ans += s.size() - r;
//
//                // 再收缩左边界
//                if (path[s[l] - 'a'] <= cnts[s[l] - 'a']) {  // 修复：<= 而不是 ==
//                    need++;
//                }
//                path[s[l] - 'a']--;
//                l++;
//            }
//        }
//
//        return ans;
//    }
//};

//leetcode submit region end(Prohibit modification and deletion)
