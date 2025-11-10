// 2025-11-03 09:05:47
#include <bits/stdc++.h>
#include <DisplayHelper.h>
#include <Heap.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//You are given an array of non-negative integers nums and an integer k. In one 
//operation, you may choose any element from nums and increment it by 1. 
//
// Return the maximum product of nums after at most k operations. Since the 
//answer may be very large, return it modulo 10⁹ + 7. Note that you should maximize 
//the product before taking the modulo. 
//
// 
// Example 1: 
//
// 
//Input: nums = [0,4], k = 5
//Output: 20
//Explanation: Increment the first number 5 times.
//Now nums = [5, 4], with a product of 5 * 4 = 20.
//It can be shown that 20 is maximum product possible, so we return 20.
//Note that there may be other ways to increment nums to have the maximum 
//product.
// 
//
// Example 2: 
//
// 
//Input: nums = [6,3,3,2], k = 2
//Output: 216
//Explanation: Increment the second number 1 time and increment the fourth 
//number 1 time.
//Now nums = [6, 4, 3, 3], with a product of 6 * 4 * 3 * 3 = 216.
//It can be shown that 216 is maximum product possible, so we return 216.
//Note that there may be other ways to increment nums to have the maximum 
//product.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length, k <= 10⁵ 
// 0 <= nums[i] <= 10⁶ 
// 
//
// Related Topics 贪心 数组 堆（优先队列） 👍 39 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#define MOD 1'000'000'007

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0] + k;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& num : nums) pq.push(num);

        while (k > 0) {
            auto cur = pq.top(); pq.pop();
            if (k >= (pq.top() + 1 - cur)) {
                k -= pq.top() + 1 - cur;
                pq.push(pq.top() + 1);  // 可以加到pq.top() + 1 然后就要等另外一个数赶上来了
            } else { // 如果k较小,就直接结束了
                pq.push(cur + k);
                k = 0;
            }
        }

        long long ans = 1;
        while (!pq.empty()) {
            ans = (ans * pq.top()) % MOD;
            pq.pop();
        }
        return ans % MOD;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
