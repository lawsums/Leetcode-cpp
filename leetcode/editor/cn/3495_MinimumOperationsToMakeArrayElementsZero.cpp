// 2025-09-06 09:51:45
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//You are given a 2D array queries, where queries[i] is of the form [l, r]. 
//Each queries[i] defines an array of integers nums consisting of elements ranging 
//from l to r, both inclusive. 
//
// In one operation, you can: 
//
// 
// Select two integers a and b from the array. 
// Replace them with floor(a / 4) and floor(b / 4). 
// 
//
// Your task is to determine the minimum number of operations required to 
//reduce all elements of the array to zero for each query. Return the sum of the 
//results for all queries. 
//
// 
// Example 1: 
//
// 
// Input: queries = [[1,2],[2,4]] 
// 
//
// Output: 3 
//
// Explanation: 
//
// For queries[0]: 
//
// 
// The initial array is nums = [1, 2]. 
// In the first operation, select nums[0] and nums[1]. The array becomes [0, 0].
// 
// The minimum number of operations required is 1. 
// 
//
// For queries[1]: 
//
// 
// The initial array is nums = [2, 3, 4]. 
// In the first operation, select nums[0] and nums[2]. The array becomes [0, 3, 
//1]. 
// In the second operation, select nums[1] and nums[2]. The array becomes [0, 0,
// 0]. 
// The minimum number of operations required is 2. 
// 
//
// The output is 1 + 2 = 3. 
//
// Example 2: 
//
// 
// Input: queries = [[2,6]] 
// 
//
// Output: 4 
//
// Explanation: 
//
// For queries[0]: 
//
// 
// The initial array is nums = [2, 3, 4, 5, 6]. 
// In the first operation, select nums[0] and nums[3]. The array becomes [0, 3, 
//4, 1, 6]. 
// In the second operation, select nums[2] and nums[4]. The array becomes [0, 3,
// 1, 1, 1]. 
// In the third operation, select nums[1] and nums[2]. The array becomes [0, 0, 
//0, 1, 1]. 
// In the fourth operation, select nums[3] and nums[4]. The array becomes [0, 0,
// 0, 0, 0]. 
// The minimum number of operations required is 4. 
// 
//
// The output is 4. 
//
// 
// Constraints: 
//
// 
// 1 <= queries.length <= 10⁵ 
// queries[i].length == 2 
// queries[i] == [l, r] 
// 1 <= l < r <= 10⁹ 
// 
//
// Related Topics 位运算 数组 数学 👍 10 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <ranges>

#if defined(__GNUC__) || defined(__clang__)
// 使用GCC/Clang内置函数
int getBinaryMSB(int n) {
    if (n == 0) return 0;

    // 计算前导零的个数，然后计算最高位位置
    return sizeof(n) * 8 - __builtin_clz(n);
}

int getBinaryMSB(unsigned int n) {
    if (n == 0) return 0;
    return sizeof(n) * 8 - __builtin_clz(n);
}

int getBinaryMSBValue(int n) {
    if (n == 0) return 0;
    return 1 << (sizeof(n) * 8 - __builtin_clz(n) - 1);
}
#endif

typedef long long ll;

class Solution {
public:
     ll minOperations(vector<vector<int>>& queries) {
        // 通过ranges:: 取得递增列表
        int r_max = ranges::max(queries | views::transform([](const auto& q) {
                                    return q[1];
                                }));

        // 如何快速地取最高位
        vector<int> arr(r_max + 1);
        for (int i = 0; i < r_max + 1; i++) {
             arr[i] = (getBinaryMSB(i) + 1) / 2;
        }

        // 构造前缀和
        vector<ll> pre(arr.begin(), arr.end());
        for (int i = 1; i < r_max + 1; i++) {
            pre[i] += pre[i - 1];
        }

        // 处理逻辑
        ll cur = 0, ans = 0;
        for (const auto& query : queries) {
            ll l = query[0], r = query[1];
            ll presum = pre[r] - (l != 0 ? pre[l - 1] : 0);
            ll high = arr[r];

            if (high > presum - high) {
                cur = presum - high + (2 * high  - presum + 1) / 2;
            } else {
                cur = (presum + 1) / 2; // 向上取整
            }
            ans += cur;
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<vector<int>> queries = {{2,6}};
    Solution().minOperations(queries);
}