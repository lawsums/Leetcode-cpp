// 2025-09-11 17:02:47
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//You are given a sorted array consisting of only integers where every element 
//appears exactly twice, except for one element which appears exactly once. 
//
// Return the single element that appears only once. 
//
// Your solution must run in O(log n) time and O(1) space. 
//
// 
// Example 1: 
// Input: nums = [1,1,2,3,3,4,4,8,8]
//Output: 2
// 
// Example 2: 
// Input: nums = [3,3,7,7,10,11,11]
//Output: 10
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// 0 <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 二分查找 👍 747 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int n = nums.size();

        // 设几个特例
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n  -1];

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
                return nums[m];
            } else if (nums[m | 1] == nums[m & (~1)]) { // 说明前面都是连续的2个元素
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return nums[l];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
