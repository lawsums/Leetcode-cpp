// 2025-09-11 16:02:50
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given a sorted array of distinct integers and a target value, return the 
//index if the target is found. If not, return the index where it would be if it were 
//inserted in order. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,3,5,6], target = 5
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: nums = [1,3,5,6], target = 2
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: nums = [1,3,5,6], target = 7
//Output: 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// nums contains distinct values sorted in ascending order. 
// -10⁴ <= target <= 10⁴ 
// 
//
// Related Topics 数组 二分查找 👍 2559 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
         while (l <= r) { // 小于等于
             m = l + (r - l) / 2; // 防止int类型溢出
             if (target > nums[m]) { l = m + 1; }
             else if (target < nums[m]) { r = m - 1; }
             else { return m; }
         }
         return l;
         // l 代表 第一个 ≥ target 的位置
         // r 代表 最后一个 < target 的位置
    }
};
//leetcode submit region end(Prohibit modification and deletion)
