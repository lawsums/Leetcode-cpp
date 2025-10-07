// 2025-08-27 12:07:34
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

//Given an array of integers nums and an integer k, return the number of 
//contiguous subarrays where the product of all the elements in the subarray is strictly 
//less than k. 
//
// 
// Example 1: 
//
// 
//Input: nums = [10,5,2,6], k = 100
//Output: 8
//Explanation: The 8 subarrays that have product less than 100 are:
//[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
//Note that [10, 5, 2] is not included as the product of 100 is not strictly 
//less than k.
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3], k = 0
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 3 * 10⁴ 
// 1 <= nums[i] <= 1000 
// 0 <= k <= 10⁶ 
// 
//
// Related Topics 数组 二分查找 前缀和 滑动窗口 👍 873 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // 1 <= nums[i] <= 1000
        // 因为数字限制,所以乘积只会增大不会减小,具有单调性
        int ans = 0;
        for (int l = 0, r = 0, cur = 1; r < nums.size(); r++) {
            cur *= nums[r];
            while (l < r && cur >= k) { // 严格小于所以是>=
                cur /= nums[l++];
            }
            ans += cur < k  ? r - l + 1 : 0;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
