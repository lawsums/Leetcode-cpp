// 2025-09-27 00:26:55
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//A binary string is monotone increasing if it consists of some number of 0's (
//possibly none), followed by some number of 1's (also possibly none). 
//
// You are given a binary string s. You can flip s[i] changing it from 0 to 1 
//or from 1 to 0. 
//
// Return the minimum number of flips to make s monotone increasing. 
//
// 
// Example 1: 
//
// 
//Input: s = "00110"
//Output: 1
//Explanation: We flip the last digit to get 00111.
// 
//
// Example 2: 
//
// 
//Input: s = "010110"
//Output: 2
//Explanation: We flip to get 011111, or alternatively 000111.
// 
//
// Example 3: 
//
// 
//Input: s = "00011000"
//Output: 2
//Explanation: We flip to get 00000000.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁵ 
// s[i] is either '0' or '1'. 
// 
//
// Related Topics 字符串 动态规划 👍 385 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> pre(s.size(), 0);
        vector<int> suf(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            pre[i] = pre[i - 1] + (int)(s[i - 1] == '1');
        }
        for (int i = s.size() - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + (int)(s[i + 1] == '0');
        }

//        print_fmt("pre: {0}\nsuf: {1}", pre, suf);
        int ans = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            ans = min(ans, pre[i] + suf[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    string s = "00110";
    Solution().minFlipsMonoIncr(s);
}