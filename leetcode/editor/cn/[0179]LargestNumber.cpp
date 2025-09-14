// 2025-09-13 20:00:21
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given a list of non-negative integers nums, arrange them such that they form 
//the largest number and return it. 
//
// Since the result may be very large, so you need to return a string instead 
//of an integer. 
//
// 
// Example 1: 
//
// 
//Input: nums = [10,2]
//Output: "210"
// 
//
// Example 2: 
//
// 
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 10⁹ 
// 
//
// Related Topics 贪心 数组 字符串 排序 👍 1360 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ss;
        for (const auto& num : nums) {
            ss.push_back(to_string(num));
        }

        sort(ss.begin(), ss.end(), [](string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        });

        if (ss[0] == "0") {
            return "0";
        } // 很重要

        string ans;
        for (const auto& elem : ss) {
            ans.append(elem);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
