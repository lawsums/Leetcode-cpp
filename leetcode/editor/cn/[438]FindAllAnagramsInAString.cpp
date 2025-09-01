// 2025-08-28 10:16:13
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given two strings s and p, return an array of all the start indices of p's 
//anagrams in s. You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: s = "cbaebabacd", p = "abc"
//Output: [0,6]
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
// 
//
// Example 2: 
//
// 
//Input: s = "abab", p = "ab"
//Output: [0,1,2]
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length, p.length <= 3 * 10⁴ 
// s and p consist of lowercase English letters. 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 1737 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int dept = p.size(), k = p.size();
        vector<int> cnts(26, 0);
        for (const auto & c : p) {
            cnts[c - 'a']++;
        }
        vector<int> ans;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (cnts[s[r] - 'a']-- > 0) dept--;

            if (r - l + 1 >= k) { // 此时窗口范围为k
                if (dept == 0) ans.push_back(l);
                if (cnts[s[l++] - 'a']++ >= 0) dept++; // 没有欠债的字符此时都是负数
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution().findAnagrams("cbaebabacd",
                            "abc");
}