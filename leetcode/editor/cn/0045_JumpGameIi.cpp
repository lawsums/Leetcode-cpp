// 2025-09-25 22:37:35
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//You are given a 0-indexed array of integers nums of length n. You are 
//initially positioned at index 0. 
//
// Each element nums[i] represents the maximum length of a forward jump from 
//index i. In other words, if you are at index i, you can jump to any index (i + j) 
//where: 
//
// 
// 0 <= j <= nums[i] and 
// i + j < n 
// 
//
// Return the minimum number of jumps to reach index n - 1. The test cases are 
//generated such that you can reach index n - 1. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,1,1,4]
//Output: 2
//Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 
//step from index 0 to 1, then 3 steps to the last index.
// 
//
// Example 2: 
//
// 
//Input: nums = [2,3,0,1,4]
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// 0 <= nums[i] <= 1000 
// It's guaranteed that you can reach nums[n - 1]. 
// 
//
// Related Topics 贪心 数组 动态规划 👍 2896 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        for (int i = 0; i < nums.size(); i++) {
            nums[i] += i;
        } // 此时nums[i]表示能跳到的最大位置

        int max_id = 0;
        int cnt = 1, ix = 1;
        while (nums[max_id] < nums.size() - 1) {
            for (; ix < nums.size() && ix <= nums[max_id]; ix++) {
                if (nums[max_id] < nums[ix]) {
                    max_id = ix;
                }
            }
            cnt++;
        }

        return cnt;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << Solution().jump(nums) << endl;
}