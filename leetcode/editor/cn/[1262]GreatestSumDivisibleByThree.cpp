// 2025-09-10 15:33:50
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given an integer array nums, return the maximum possible sum of elements of 
//the array such that it is divisible by three. 
//
// 
// Example 1: 
//
// 
//Input: nums = [3,6,5,1,8]
//Output: 18
//Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum 
//divisible by 3). 
//
// Example 2: 
//
// 
//Input: nums = [4]
//Output: 0
//Explanation: Since 4 is not divisible by 3, do not pick any number.
// 
//
// Example 3: 
//
// 
//Input: nums = [1,2,3,4,4]
//Output: 12
//Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum 
//divisible by 3).
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 4 * 10⁴ 
// 1 <= nums[i] <= 10⁴ 
// 
//
// Related Topics 贪心 数组 动态规划 排序 👍 375 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> dp;

public:
    int maxSumDivThree(vector<int>& nums) {
         function<void(int, int)> f = [&](int i, int j) {
            if (i == 0) return 0;
            if (dp[i][j] != -1)  return dp[i][j];

            dp[i][j] = max(f(i - 1,j),
                           f(i - 1, (((j - nums[i - 1]) % 3) + 3) % 3)
                                   + nums[i - 1]
                           );
            return dp[i][j];
        }

        int n = nums.size();
        dp.assign(n, vector<int>(3));
        dp[0][0] = 0;
        for (int j = 1; j < 3; j++) {
            dp[0][j] = -1;
        }

        for (int i = 1, x, cur, need; i <= n; i++) {
            x = nums[i - 1];
            cur = nums[i - 1] % 3;
            for (int j = 0; j < 3; j++) {
                dp[i][j] = dp[i - 1][j];
                need = cur
            }
        }

        return f(n, 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
