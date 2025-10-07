// 2025-09-10 14:55:52
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given an integer array nums, find a subarray that has the largest product, 
//and return the product. 
//
// The test cases are generated so that the answer will fit in a 32-bit integer.
// 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
// 
//
// Example 2: 
//
// 
//Input: nums = [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 2 * 10⁴ 
// -10 <= nums[i] <= 10 
// The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
// 
// 
//
// Related Topics 数组 动态规划 👍 2483 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxPre = nums[0], minPre = nums[0], ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tempMax = maxPre;
            maxPre = max(nums[i], max(maxPre * nums[i], minPre * nums[i]));
            minPre = min(nums[i], min(tempMax * nums[i], minPre * nums[i]));
            ans = max(ans, maxPre);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
