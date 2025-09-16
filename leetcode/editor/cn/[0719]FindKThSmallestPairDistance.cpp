// 2025-09-15 13:03:51
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//The distance of a pair of integers a and b is defined as the absolute 
//difference between a and b. 
//
// Given an integer array nums and an integer k, return the kᵗʰ smallest 
//distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,3,1], k = 1
//Output: 0
//Explanation: Here are all the pairs:
//(1,3) -> 2
//(1,1) -> 0
//(3,1) -> 2
//Then the 1ˢᵗ smallest distance pair is (1,1), and its distance is 0.
// 
//
// Example 2: 
//
// 
//Input: nums = [1,1,1], k = 2
//Output: 0
// 
//
// Example 3: 
//
// 
//Input: nums = [1,6,1], k = 3
//Output: 5
// 
//
// 
// Constraints: 
//
// 
// n == nums.length 
// 2 <= n <= 10⁴ 
// 0 <= nums[i] <= 10⁶ 
// 1 <= k <= n * (n - 1) / 2 
// 
//
// Related Topics 数组 双指针 二分查找 排序 👍 491 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
 #include "../../../DisplayHelper.h"
 using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int k;

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        this->k = k;
        ranges::sort(nums);  // 排序

        // 二分
        int l = 0, r = nums.back() - nums.front();
        int ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2; // 计算当前允许差值
            if (check(nums, m)) {
                r = m - 1;
                ans = m;
            } else l = m + 1;
        }

        return ans;
    }

    bool check(vector<int>& nums, int tolerance) {
        int ans = 0;
        for (int l = 0, r = 1, cur = 0; l < nums.size(); l++) {
            while (r < nums.size() && nums[r] - nums[l] <= tolerance) { r++; }
            ans += r - l - 1;
        }
        return ans >= k;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> nums = {1, 3, 1};
    int k = 1;
    int ans = Solution().smallestDistancePair(nums, k);
    cout << "ans: " << ans << endl;
}