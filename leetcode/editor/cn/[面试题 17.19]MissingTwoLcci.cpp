// 2025-08-28 01:25:21
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//You are given an array with all the numbers from 1 to N appearing exactly 
//once, except for two number that is missing. How can you find the missing number in 
//O(N) time and 0(1) space? 
//
// You can return the missing numbers in any order. 
//
// Example 1: 
//
// 
//Input: [1]
//Output: [2,3] 
//
// Example 2: 
//
// 
//Input: [2,3]
//Output: [1,4] 
//
// Note: 
//
// 
// nums.length <= 30000 
// 
//
// Related Topics 位运算 数组 哈希表 👍 242 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        int xorsum = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
            return a ^ b;
        });
        for (int i = 1; i <= n; i++) {
            xorsum ^= i;
        }

        // 防止溢出
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        for (int num : nums) {
            if (num & lsb)  type1 ^= num; // type1含有两者最低不同位的数
            else            type2 ^= num; // type2没有
        }

        for (int i = 1; i <= n; i++) {
            if (i & lsb)  type1 ^= i;
                    else  type2 ^= i;
        }

        return {type1, type2};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
