// 2025-09-15 10:10:39
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given an integer array nums and an integer k, split nums into k non-empty 
//subarrays such that the largest sum of any subarray is minimized. 
//
// Return the minimized largest sum of the split. 
//
// A subarray is a contiguous part of the array. 
//
// 
// Example 1: 
//
// 
//Input: nums = [7,2,5,10,8], k = 2
//Output: 18
//Explanation: There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8], where the largest sum 
//among the two subarrays is only 18.
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3,4,5], k = 2
//Output: 9
//Explanation: There are four ways to split nums into two subarrays.
//The best way is to split it into [1,2,3] and [4,5], where the largest sum 
//among the two subarrays is only 9.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 1000 
// 0 <= nums[i] <= 10⁶ 
// 1 <= k <= min(50, nums.length) 
// 
//
// Related Topics 贪心 数组 二分查找 动态规划 前缀和 👍 1076 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int k;
    int sum;

public:
    int splitArray(vector<int>& nums, int k) {
        this->k = k;
        this->sum = accumulate(nums.begin(), nums.end(), 0);
        int l = 0, r = sum;
        int ans = 0;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(nums, m)) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }

    bool check(vector<int>& nums, int capacity) {
        if (sum == 0) return true;

        int t = 1; // 如果不是零的话，怎么都需要起码一个容器
        for (int i = 0, cur = 0; i < nums.size(); i++) {
            if (cur + nums[i] > capacity) {
                cur = 0;
                t++; // 需要另起一个新的容器
            }

            if (nums[i] <= capacity) cur += nums[i];
            else return false; // 如果容量小于一个元素，说明无论如何都无法完成
        }

        return t <= k;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
