// 2025-08-28 09:39:53
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//English description is not available for the problem. Please switch to 
//Chinese. 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 137 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        // 删除大小写转换！
        // 不要修改 s 和 t 的大小写

        vector<int> cnts(128, 0); // 使用 ASCII 码，支持大小写字母
        vector<bool> need(128, false);
        int dept = t.size(); // 债务：还需要匹配的字符总数

        // 统计 t 中每个字符的频次
        for (char c : t) {
            cnts[c]++;
            need[c] = true;
        }

        pair<int, int> res{0, INT_MAX};

        for (int l = 0, r = 0; r < s.size(); r++) {
            char cr = s[r];
            if (need[cr]) {
                if (cnts[cr] > 0) {
                    dept--; // 只有在还需要这个字符时才减少债务
                }
                cnts[cr]--;
            }

            // 尝试收缩左窗口
            while (dept <= 0) {
                // 检查当前窗口是否覆盖 t
                if (dept == 0) {
                    if (r - l < res.second - res.first) {
                        res = {l, r};
                    }
                }

                char cl = s[l];
                if (need[cl]) {
                    cnts[cl]++;
                    if (cnts[cl] > 0) {
                        dept++; // 归还一个所需字符
                    }
                }
                l++;

                // 如果 dept > 0，跳出收缩
                if (dept > 0) break;
            }
        }

        int left = res.first, right = res.second;
        return right == INT_MAX ? "" : s.substr(left, right - left + 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main () {
    Solution().minWindow("ADOBECODEBANC",
                         "ABC");
}