// 2025-10-08 16:58:56
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//Given a string s consisting only of characters a, b and c. 
//
// Return the number of substrings containing at least one occurrence of all 
//these characters a, b and c. 
//
// 
// Example 1: 
//
// 
//Input: s = "abcabc"
//Output: 10
//Explanation: The substrings containing at least one occurrence of the 
//characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", 
//"cab", "cabc" and "abc" (again). 
// 
//
// Example 2: 
//
// 
//Input: s = "aaacb"
//Output: 3
//Explanation: The substrings containing at least one occurrence of the 
//characters a, b and c are "aaacb", "aacb" and "acb". 
// 
//
// Example 3: 
//
// 
//Input: s = "abc"
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 3 <= s.length <= 5 x 10^4 
// s only consists of a, b or c characters. 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 151 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfSubstrings(string& s) {
        vector<int> cnts(26, 0);
        vector<int> path(26, 0);
        string word2 = "abc";
        int need = word2.size();

        for (const auto c : word2) {
            cnts[c - 'a']++;
        }

        int ans = 0;
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
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    string s = "aaacb";
    cout << Solution().numberOfSubstrings(s) << endl;
}