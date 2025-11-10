// 2025-11-10 00:00:35
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


//You are given an array nums of size n, consisting of non-negative integers. 
//Your task is to apply some (possibly zero) operations on the array so that all 
//elements become 0. 
//
// In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) 
//and set all occurrences of the minimum non-negative integer in that subarray to 0.
// 
//
// Return the minimum number of operations required to make all elements in the 
//array 0. 
//
// 
// Example 1: 
//
// 
// Input: nums = [0,2] 
// 
//
// Output: 1 
//
// Explanation: 
//
// 
// Select the subarray [1,1] (which is [2]), where the minimum non-negative 
//integer is 2. Setting all occurrences of 2 to 0 results in [0,0]. 
// Thus, the minimum number of operations required is 1. 
// 
//
// Example 2: 
//
// 
// Input: nums = [3,1,2,1] 
// 
//
// Output: 3 
//
// Explanation: 
//
// 
// Select subarray [1,3] (which is [1,2,1]), where the minimum non-negative 
//integer is 1. Setting all occurrences of 1 to 0 results in [3,0,2,0]. 
// Select subarray [2,2] (which is [2]), where the minimum non-negative integer 
//is 2. Setting all occurrences of 2 to 0 results in [3,0,0,0]. 
// Select subarray [0,0] (which is [3]), where the minimum non-negative integer 
//is 3. Setting all occurrences of 3 to 0 results in [0,0,0,0]. 
// Thus, the minimum number of operations required is 3. 
// 
//
// Example 3: 
//
// 
// Input: nums = [1,2,1,2,1,2] 
// 
//
// Output: 4 
//
// Explanation: 
//
// 
// Select subarray [0,5] (which is [1,2,1,2,1,2]), where the minimum non-
//negative integer is 1. Setting all occurrences of 1 to 0 results in [0,2,0,2,0,2]. 
// Select subarray [1,1] (which is [2]), where the minimum non-negative integer 
//is 2. Setting all occurrences of 2 to 0 results in [0,0,0,2,0,2]. 
// Select subarray [3,3] (which is [2]), where the minimum non-negative integer 
//is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,2]. 
// Select subarray [5,5] (which is [2]), where the minimum non-negative integer 
//is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,0]. 
// Thus, the minimum number of operations required is 4. 
// 
//
// 
// Constraints: 
//
// 
// 1 <= n == nums.length <= 10⁵ 
// 0 <= nums[i] <= 10⁵ 
// 
//
// Related Topics 栈 贪心 数组 哈希表 单调栈 👍 20 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> left(nums.size(), -1);
        vector<int> stk;
        unordered_map<int, int> last_map; // num -> index
          
        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && nums[i] < nums[stk.back()]) {
                stk.pop_back();
            }
            if (!stk.empty() && nums[i] > nums[stk.back()]) {
                left[i] = stk.back();
                stk.push_back(i);
            }

            if (stk.empty()) {
                stk.push_back(i);
            } // stk不为空


        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
