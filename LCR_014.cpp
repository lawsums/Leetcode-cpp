//
// Created by Hello on 2025/8/26.
//
// 2025-08-26 19:52:08
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。
//
//  换句话说，第一个字符串的排列之一是第二个字符串的 子串 。
//
//
//
//  示例 1：
//
//
// 输入: s1 = "ab" s2 = "eidbaooo"
// 输出: True
// 解释: s2 包含 s1 的排列之一 ("ba").
//
//
//  示例 2：
//
//
// 输入: s1= "ab" s2 = "eidboaoo"
// 输出: False
//
//
//
//
//  提示：
//
//
//  1 <= s1.length, s2.length <= 10⁴
//  s1 和 s2 仅包含小写字母
//
//
//
//
//
//  注意：本题与主站 567 题相同：
//  https://leetcode-cn.com/problems/permutation-in-string/
//
//  Related Topics 哈希表 双指针 字符串 滑动窗口 👍 111 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp(26, 0);
        int dept = 0;
        int n = s2.size();
        for (int i = 0; i < s1.size(); i++) {
            mp[s1[i] - 'a']++;
            dept++;
        }
        for (int l = 0, r = 0; r < n; r++) {// 欠债模型
            mp[s2[r] - 'a']--;
            dept--;
            while (mp[s2[r] - 'a'] < 0) {// 还过头了
                mp[s2[l++] - 'a']++;     // 指针左移退还债务
                dept++;
            }
            // 检测是否还完了
            if (dept == 0) {// 债务还完了,不可能错,因为但凡有一次换错了,就会指针左移
                return true;
            }
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main() {
    string s1 = "ab", s2 = "eidbaooo";
    cout << Solution().checkInclusion(s1, s2) << endl;
    return 0;
}