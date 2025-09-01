// 2025-08-28 10:53:51
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Given a string s, find the length of the longest substring without duplicate 
//characters. 
//
// 
// Example 1: 
//
// 
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
// 
//
// Example 2: 
//
// 
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
// 
//
// Example 3: 
//
// 
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a 
//substring.
// 
//
// 
// Constraints: 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s consists of English letters, digits, symbols and spaces. 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 10994 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return f2(s);
    }

    static int f1(string& s) {
        vector<int> last(128, -1);
        int ans = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            l = max(l, last[s[r]] + 1); // 维护窗口左边界
            ans = max(ans, r - l + 1);
            last[s[r]] = r;
        }
        return ans;
    }

    int f2(string& s) {
        unordered_map<char, int> mp;
        int ans = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            while (mp.count(s[r])) {
                if (mp[s[l]] == 1) mp.erase(s[l]); // 删除这个键
                else mp[s[l]]--;
                l++;
            } // ready_to_update
            ans = max(ans, r - l + 1);
            mp[s[r]]++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
}