// 2025-09-22 10:51:14
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given a string s, partition s such that every substring of the partition is a 
//palindrome. Return all possible palindrome partitioning of s. 
//
// 
// Example 1: 
// Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
// 
// Example 2: 
// Input: s = "a"
//Output: [["a"]]
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 16 
// s contains only lowercase English letters. 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 2099 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
 #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> path;
    vector<vector<string>> ans;

public:
    void dfs(int step, string& s) {
        if (step > s.size()) return;
        if (step == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = step; i < s.size(); i++) {
            if (check(step, i, s)) {
                path.push_back(s.substr(step, i - step + 1));
                dfs(i + 1, s); // 继续判断
                path.pop_back(); // 回溯
            }
        }
    }

    bool check(int l, int r, string& s) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    string s = "aab";
    auto ans = Solution().partition(s);
    display::print(ans);
}