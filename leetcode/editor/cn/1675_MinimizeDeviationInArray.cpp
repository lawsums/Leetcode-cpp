// 2025-09-26 12:35:29
#include <bits/stdc++.h>
//#include <DisplayHelper.h>
//#include <ListOperations.h>
//#include <StringOperations.h>
//#include <TreeOperations.h>
//#include <RandomHelper.h>
//#include <ComparatorHelper.h>

using namespace std;
// using namespace display;

//You are given an array nums of n positive integers. 
//
// You can perform two types of operations on any element of the array any 
//number of times: 
//
// 
// If the element is even, divide it by 2. 
// 
//
// 
// For example, if the array is [1,2,3,4], then you can do this operation on 
//the last element, and the array will be [1,2,3,2]. 
// 
// 
// If the element is odd, multiply it by 2.
// 
// For example, if the array is [1,2,3,4], then you can do this operation on 
//the first element, and the array will be [2,2,3,4]. 
// 
// 
//
//
// The deviation of the array is the maximum difference between any two 
//elements in the array. 
//
// Return the minimum deviation the array can have after performing some number 
//of operations. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3,4]
//Output: 1
//Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], 
//then the deviation will be 3 - 2 = 1.
// 
//
// Example 2: 
//
// 
//Input: nums = [4,1,5,20,3]
//Output: 3
//Explanation: You can transform the array after two operations to [4,2,5,5,3], 
//then the deviation will be 5 - 2 = 3.
// 
//
// Example 3: 
//
// 
//Input: nums = [2,10,8]
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// n == nums.length 
// 2 <= n <= 5 * 10⁹ 
// 
//
// Related Topics 贪心 数组 有序集合 堆（优先队列） 👍 125 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int min_ = INT_MAX;
        for (auto& num : nums) {
            if (num % 2 == 1) { num *= 2; } // 先将所有的奇数变为偶数
            if (num < min_) min_ = num;
        }


        // 然后加入优先队列
        priority_queue<int> pq;
        for (const auto& num : nums) {
            pq.push(num);
        }

        int ans = pq.top() - min_;
        while (pq.top() % 2 == 0) {
            int cur = pq.top(); pq.pop();
            cur /= 2;
            pq.push(cur); // 如果还是偶数就放回去
            // 计算当前差值
            if (cur < min_) min_ = cur;
            ans = min(ans, pq.top() - min_); // 更新答案
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

