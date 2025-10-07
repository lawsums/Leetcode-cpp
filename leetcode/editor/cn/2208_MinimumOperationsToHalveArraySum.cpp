// 2025-09-06 16:29:11
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//You are given an array nums of positive integers. In one operation, you can 
//choose any number from nums and reduce it to exactly half the number. (Note that 
//you may choose this reduced number in future operations.) 
//
// Return the minimum number of operations to reduce the sum of nums by at 
//least half. 
//
// 
// Example 1: 
//
// 
//Input: nums = [5,19,8,1]
//Output: 3
//Explanation: The initial sum of nums is equal to 5 + 19 + 8 + 1 = 33.
//The following is one of the ways to reduce the sum by at least half:
//Pick the number 19 and reduce it to 9.5.
//Pick the number 9.5 and reduce it to 4.75.
//Pick the number 8 and reduce it to 4.
//The final array is [5, 4.75, 4, 1] with a total sum of 5 + 4.75 + 4 + 1 = 14.7
//5. 
//The sum of nums has been reduced by 33 - 14.75 = 18.25, which is at least 
//half of the initial sum, 18.25 >= 33/2 = 16.5.
//Overall, 3 operations were used so we return 3.
//It can be shown that we cannot reduce the sum by at least half in less than 3 
//operations.
// 
//
// Example 2: 
//
// 
//Input: nums = [3,8,20]
//Output: 3
//Explanation: The initial sum of nums is equal to 3 + 8 + 20 = 31.
//The following is one of the ways to reduce the sum by at least half:
//Pick the number 20 and reduce it to 10.
//Pick the number 10 and reduce it to 5.
//Pick the number 3 and reduce it to 1.5.
//The final array is [1.5, 8, 5] with a total sum of 1.5 + 8 + 5 = 14.5. 
//The sum of nums has been reduced by 31 - 14.5 = 16.5, which is at least half 
//of the initial sum, 16.5 >= 31/2 = 15.5.
//Overall, 3 operations were used so we return 3.
//It can be shown that we cannot reduce the sum by at least half in less than 3 
//operations.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// 1 <= nums[i] <= 10⁷ 
// 
//
// Related Topics 贪心 数组 堆（优先队列） 👍 97 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <queue>

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double, vector<double>, less<double>> pq; // 最大堆

        double sum = 0;
        for (const auto& num : nums) {
            sum += num;
            pq.push(num);
        }

        double cur = 0;
        int cnt = 0;
        while (cur < sum - cur) {
            double tmp = pq.top() / 2.0;
            cur += tmp; cnt++;
            pq.pop();
            pq.push(tmp);
        }

        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
