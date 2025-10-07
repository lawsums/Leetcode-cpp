// 2025-09-22 11:05:25
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//A valid IP address consists of exactly four integers separated by single dots.
// Each integer is between 0 and 255 (inclusive) and cannot have leading zeros. 
//
// 
// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011
//.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 
// 
//
// Given a string s containing only digits, return all possible valid IP 
//addresses that can be formed by inserting dots into s. You are not allowed to reorder 
//or remove any digits in s. You may return the valid IP addresses in any order. 
//
// 
// Example 1: 
//
// 
//Input: s = "25525511135"
//Output: ["255.255.11.135","255.255.111.35"]
// 
//
// Example 2: 
//
// 
//Input: s = "0000"
//Output: ["0.0.0.0"]
// 
//
// Example 3: 
//
// 
//Input: s = "101023"
//Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 20 
// s consists of digits only. 
// 
//
// Related Topics 字符串 回溯 👍 1541 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
 #include "../../../include/DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> path;
    vector<vector<string>> ans;
    vector<string> res;

public:
    bool check(int start, int end, string& s) {
        if (s[start] == '0' && start != end) return false;

        int num = 0;
        for (int i = start; i <= end; i++) {
            num *= 10;
            num += s[i] - '0';
        }

        return 0 <= num && num <= 255;
    }

    void dfs(int step, int begin, string& s) {
        if (step > 4 || begin > s.size()) return;
        if (step == 4 && begin == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (check(begin, begin + i, s)) {
                path.push_back(s.substr(begin, i + 1));
                dfs(step + 1, begin + i + 1, s);
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
         dfs(0, 0, s);

         for (const auto& row : ans) {
             string tmp;
             for (int i = 0; i < row.size(); i++) {
                 tmp.append(row[i]);
                 if (i != row.size() - 1) {
                     tmp.push_back('.');
                 }
             }
             res.push_back(tmp);
         }

         return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    string s = "25525511135";
    auto ans = Solution().restoreIpAddresses(s);
    display::print(ans);
}